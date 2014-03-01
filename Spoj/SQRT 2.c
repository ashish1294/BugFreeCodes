/*
** Pascal Sebah : July 1999
**
** Subject:
**
**    A very easy program to compute sqrt(2) with many digits.
**    No optimisations, no tricks, just a basic program to learn how
**    to compute in multiprecision.
**
** Formula:
**
**    sqrt(2) = (239/169)*1/sqrt(1-1/57122)
**
** Data:
**
**    A big real (or multiprecision real) is defined in base B as:
**      X = x(0) + x(1)/B^1 + ... + x(n-1)/B^(n-1)
**      where 0<=x(i)<B
**
** Results: (PentiumII, 450Mhz)
**
**    1000   decimals :   0.02seconds
**    10000  decimals :   1.7s
**    100000 decimals : 176.0s
**
** With a little work it's possible to reduce those computation
** times by a factor of 3 and more.
*/
#include <stdio.h>
#include <malloc.h>
long B=10000; /* Working base */
long LB=4;    /* Log10(base)  */
/*
** Set the big real x to the small integer Integer
*/
void SetToInteger (long n, long *x, long Integer) {
  long i;
  for (i=1; i<n; i++) x[i] = 0;
  x[0] = Integer;
}
/*
** Is the big real x equal to zero ?
*/
long IsZero (long n, long *x) {
  long i;
  for (i=0; i<n; i++)
    if (x[i])	return 0;
	return 1;
}
/*
** Addition of big reals : x += y
**  Like school addition with carry management
*/
void Add (long n, long *x, long *y) {
  long carry=0, i;
  for (i=n-1; i>=0; i--) {
    x[i] += y[i]+carry;
    if (x[i]<B) carry = 0;
    else {
      carry = 1;
      x[i] -= B;
    }
  }
}
/*
** Multiplication of the big real x by the integer q
*/
void Mul (long n, long *x, long q) {
  long carry = 0, xi, i;
  for (i=n-1; i>=0; i--) {
    xi  = x[i]*q;
    xi += carry;
    if (xi>=B) {
      carry = xi/B;
      xi -= (carry*B);
    }
    else
      carry = 0;
    x[i] = xi;
	}
}
/*
** Division of the big real x by the integer d
**  Like school division with carry management
*/
void Div (long n, long *x, long d) {
  long carry=0, xi, q, i;
  for (i=0; i<n; i++) {
    xi    = x[i]+carry*B;
    q     = xi/d;
    carry = xi-q*d;
    x[i]  = q;
  }
}
/*
** Print the big real x
*/
void Print (long n, long *x) {
  long i;
  printf ("%d.", x[0]);
  for (i=1; i<n; i++) {
    printf ("%.4d", x[i]);
    if (i%25==0) printf ("%8d\n", i*4);
  }
  printf ("\n");
}
/*
** Computation of the constant sqrt(2)
*/
void main () {
  long NbDigits=10000, size=1+NbDigits/LB;
  long *r2 = (long *)malloc(size*sizeof(long));
  long *uk = (long *)malloc(size*sizeof(long));
  long k=1;
  /*
  ** Formula used :
  **    sqrt(2) = (239/169)*1/sqrt(1-1/57122)
  ** and
  **   1/sqrt(1-x) = 1+(1/2)x+(1.3)/(2.4)x^2+(1.3.5)/(2.4.6)x^3+...
  */
  SetToInteger (size, r2, 1); /* r2 = 1 */
  SetToInteger (size, uk, 1);	/* uk = 1 */
  while (!IsZero(size, uk)) {
    Div (size, uk, 57122); /* uk = u(k-1)/57122 * (2k-1)/(2k) */
    Div (size, uk, 2*k);
    Mul (size, uk, 2*k-1);
    Add (size, r2, uk);    /* r2 = r2+uk */
    k++;
  }
  Mul (size, r2, 239);
  Div (size, r2, 169);  /* r2 = (239/169)*r2 */
  Print (size, r2);     /* Print out of sqrt(2) */
  free (r2);
 	free (uk);
}
