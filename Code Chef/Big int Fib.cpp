// Find the first 10 bytes and the last 10 bytes of f(1_000_000_000).
// That's right, fibonacci of one billion.

// I suppose the first 80 bits and the last 80 bits are more interesting,
// when you try to (dis)prove .... things.
// And, if you try, start with small numbers, first bit, last bit, first/last two bits, etc.
// By the way, the first bit is always one,
// though there is an exception, do you know it? (hint: start with small numbers)

// You can find the challenge at:
// weblogs.java.net/blog/kabutz/archive/2012/02/24/fibonacci-1000000000-challenge
// Or google "fibonacci 1000000000".

// My result(using 1 core):
//
//         F(1000000000)
//         bits: 694241913
//          MSB: 01 62 80 B8 2D 8C BE 0E DC 1B
//         time: 46 us
//          LSB: A9 53 2D F4 D2 D2 5B 5D B6 3B
//         time: 46 us

// Slightly less than 0.1 ms!!!!
// (the conversion of an 80 bits number to a string takes about 2 us, eternal question:
// can this conversion be done faster? I'm not going to answer it;)

// When the Most Significant Bytes are calculated with a precision of 80 bits,
// the lowest 2 or 3 bytes of these MSB's are wrong, if it's doubled to 160 bits,
// things look fine, are the same as those of Rex Young, which can be found at:
// weblogs.java.net/blog/kabutz/archive/2012/02/24/fibonacci-1000000000-challenge
//
// Big question: "how to (dis)prove it?"
// It probably boils down to "more bits, higher accuracy, analyse the error".
// Amazing: MSB's (multiplication of 160 bits numbers)
//      and LSB's (multiplication of  80 bits numbers)
//      take nearly the same time.
// I started with LowFib, returning the LSB's,
//   and thought HighFib, returning the MSB's,
//   would be 4 times slower.

// A few ways to speed it up:
// -upto a bitlength of 80 bits LowFib and HighFib do the same (iterations).
// -in the last iteration F(n) and F(n+1) are computed, get rid of F(n+1)
// -don't use a biginteger library, use arrays of uints,
//  and (Knuth's) classical multiplication algorithm.
// -translate it to c (or assembler)

// LSB's, 80 bits result from 80 bits multiplied by 80 bits.
// Looks like some time can be saved within the classical * algo.

// The final digits of fibonacci numbers repeat with a certain cycle length, see:
// www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html#cycles
// Looks like a modulo (remainder) operation.

// An underbound for the number of bits of fibonacci(n) is (2*n+1)/3
// Are there better bounds?

// FibonacciHighLow(10^12)? The trillionth one.
// Use a few longs, it would surprise me if it takes more than 0.2 ms.

//       !!! Project >> Add Reference >> System.Numerics !!!
using Xint = System.Numerics.BigInteger;
using System.Diagnostics;
using System;

class FibonacciHighLow
{
    private static int nob;                           // number of bits
    private static Stopwatch sw = new Stopwatch();
    static void Main()
    {
        for (int n = 1953125; n <= 1000000000; n *= 2)
        {
            Console.WriteLine("F(" + n + ")");
            string s = hexXint(HighFib(n));
            Console.WriteLine("bits: " + nob);
            Console.WriteLine(" MSB: " + s);
            HighFib(n);
            sw.Restart();
            for (int i = 0; i < 1000; i++)
            {
                HighFib(n);
                //hexXint(HighFib(n));
            }
            sw.Stop();
            Console.WriteLine("time: " + sw.ElapsedMilliseconds + " us");
            s = hexXint(LowFib(n));
            Console.WriteLine(" LSB: " + s);
            LowFib(n);
            sw.Restart();
            for (int i = 0; i < 1000; i++)
            {
                LowFib(n);
                //hexXint(LowFib(n));
            }
            sw.Stop();
            Console.WriteLine("time: " + sw.ElapsedMilliseconds + " us");
            Console.WriteLine();
        }
        Console.ReadLine();
    }

    public static Xint LowFib(int n)
    {
        Xint Mask = (Xint.One << 80) - 1;
        Xint[] F = { 0, 1 };
        for (int i = fL2(n); i >= 0; i--)             // floorLog2
        {
            Xint L = 2 * F[1] - F[0];                 // L is a Lucas Number(2,1,3,4,7,..)
            switch ((3 << i & n) >> i)
            {
                case 0: F = new Xint[2] { L * F[0], L * F[1] - 1 }; break;
                case 2: F = new Xint[2] { L * F[0], L * F[1] + 1 }; break;
                case 1: F = new Xint[2] { L * F[1] - 1, L * (F[1] + F[0]) - 1 }; break;
                case 3: F = new Xint[2] { L * F[1] + 1, L * (F[1] + F[0]) + 1 }; break;
            }
            F[0] &= Mask;
            F[1] &= Mask;
        }
        return F[0];
    }
    // To do:
    // case 0: F[1] = (L * F[1] - 1) & Mask;
    // if (F[1] < 0) F[1] = Mask; // ????
    // Looks like LowFib can be exact.
    // Test it with small Mask values (decimal 1,3,7,15,.../binary 1,11,111,1111,....)
    //    A few years ago I wrote Knuth's classical division algorithm in TWITS (TWo bITS)
    //    It's quite difficult to test it when bytes, ushorts or uints are used.
    //    With twits it's a lot easier.
    // Or, even better, don't, because:
    // mathworld.wolfram.com/FibonacciNumber.html
    // F(2^n + 2^(n+1)) ends in n+2 zeroes binary.
    // So 80 zeroes, n=78, 2^78+2^79, F(906.694.364.710.971.881.029.632) ends in 80 zeroes.

    public static Xint HighFib(int n)
    {
        Xint Mask = (Xint.One << 160) - 1;
        Xint[] F = { 0, 1 };
        int i = fL2(n);
        for (; i >= 0 && bL(F[0]) <= 160; i--)        // bitLength
        {
            Xint L = 2 * F[1] - F[0];
            switch ((3 << i & n) >> i)
            {
                case 0: F = new Xint[2] { L * F[0], L * F[1] - 1 }; break;
                case 2: F = new Xint[2] { L * F[0], L * F[1] + 1 }; break;
                case 1: F = new Xint[2] { L * F[1] - 1, L * (F[1] + F[0]) - 1 }; break;
                case 3: F = new Xint[2] { L * F[1] + 1, L * (F[1] + F[0]) + 1 }; break;
            }

        }
        int s = bL(F[0]) - 160;                       // shift
        int t = s;                                    // total shift
        F[0] >>= s;
        F[1] >>= s;
        for (; i >= 0; i--)
        {
            Xint L = 2 * F[1] - F[0];
            if ((1 << i & n) >> i == 0)
            {
                F[0] *= L; F[1] *= L;
            }
            else
            {
                F = new Xint[2] { L * F[1], L * (F[1] + F[0]) };
            }
            t *= 2;
            s = bL(F[0]) - 160;
            t += s;
            F[0] >>= s;
            F[1] >>= s;

        }
        t += bL(F[0]);
        nob = t;
        return F[0] >>= 80 + (8 - t & 7);
    }
    // mathworld.wolfram.com/FibonacciNumber.html
    // Edd Pegg Jr.'s plot(2003) might indicate that
    // repeating zeroes (binary) in Fibonacci Numbers,
    // in our case 160 zeroes, arise for F(VERY VERY LARGE)

    private static int fL2(int n) { int i = -1; while (n > 0) { i++; n /= 2; } return i; }

    private static int bL(Xint X)
    {
        byte[] bytes = X.ToByteArray();
        int i = bytes.Length - 1;
        return i * 8 | bitLengthMostSignificantByte(bytes[i]);
    }
    private static int bitLengthMostSignificantByte(byte b)
    {
        return b < 08 ? b < 02 ? b < 01 ? 0 : 1 :
                                 b < 04 ? 2 : 3 :
                        b < 32 ? b < 16 ? 4 : 5 :
                                 b < 64 ? 6 : 7;
    }

    private static string hexXint(Xint X)
    {
        byte[] bytes = X.ToByteArray();
        byte[] zeros = new byte[10];
        int i = bytes.Length;
        if (i == 11) i--;
        for (--i; i >= 0; i--)
        {
            zeros[i] = bytes[i];
        }
        string s = zeros[9].ToString("X2");
        for (i = 8; i >= 0; i--)
        {
            s += " " + zeros[i].ToString("X2");
        }
        return s;
    }
}
