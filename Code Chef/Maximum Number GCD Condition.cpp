//http://www.codechef.com/MARCH14/problems/ANUGCD
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
#define MAX 100001
#define NP 9593
#include <stdint.h>
#include <unistd.h>
class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};
class FastOutput {
	public:
		FastOutput() {
			m_dataOffset = 0;
		}
		~FastOutput() {
		}
		void Flush() {
			if (m_dataOffset) {
				if (write(1, m_data, m_dataOffset));
				m_dataOffset = 0;
			}
		}
		void PrintUint(uint32_t v, char d) {
			if (m_dataOffset + 11 > sizeof(m_data)) Flush();
			if (v < 100000) {
				if (v < 1000) {
					if (v < 10) {
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 1;
					} else if (v < 100) {
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 2;
					} else {
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 3;
					}
				} else {
					if (v < 10000) {
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 4;
					} else {
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 5;
					}
				}
			} else {
				if (v < 100000000) {
					if (v < 1000000) {
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 6;
					} else if (v < 10000000) {
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 7;
					} else {
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 8;
					}
				} else {
					if (v < 1000000000) {
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 9;
					} else {
						m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 10;
					}
				}
			}
			m_data[m_dataOffset++] = d;
		}
		void PrintChar(char d) {
			if (m_dataOffset + 1 > sizeof(m_data)) Flush();
			m_data[m_dataOffset++] = d;
		}

		void ReplaceChar(int offset, char d) {m_data[m_dataOffset + offset] = d;}
	public:
		uint8_t m_data[32768];
		size_t m_dataOffset;
};
int arr[MAX],mf[MAX],fact[MAX][8],n,prin[MAX],isn[NP],qins[NP],que[MAX][3];
struct pp{int f,s;}qans[MAX],dummy;
class node
{
    public:
    int po,qp;
    struct pp *vec,*tree;
	int *qr;
    void ini(int no, int qs)
    {
        vec = (struct pp*)malloc(sizeof(pp)*no);
        tree = (struct pp*)malloc(sizeof(pp)*(no+no+2));
		qr = (int*)malloc(sizeof(int)*qs);
        po=qp=0;
    }
	struct pp queit()
	{
		int i;
		for(i=0;i<qp;i++)
		{
			int ini=bins(que[qr[i]][1],0),inj=bins(que[qr[i]][2],1);
			if(ini<=inj)
			{
				struct pp tmp = query(0,0,po-1,ini,inj);
				if(tmp.f>qans[qr[i]].f) qans[qr[i]]=tmp;
			}
		}
	}
    struct pp init(int si,int ss,int se)
    {
        if(ss==se)
        {
            struct pp ret;
            ret.f=vec[ss].s;
            ret.s=1;
            return ret;
        }
        int mid=ss+((se-ss)>>1),next = (si<<1)+1;
        struct pp aa = init(next,ss,mid), bb = init(next+1,mid+1,se);
        if(aa.f==bb.f)
        {
            tree[si]=aa;
            tree[si].s+=bb.s;
        }
        else if(aa.f>bb.f) tree[si]=aa;
        else tree[si]=bb;
        return tree[si];
    }
    struct pp query(int si,int ss,int se,int qs,int qe)
    {
        if(qe<ss || qs>se) return dummy;
        else if(ss==se)
        {
            if(qs<=ss && qe>=se)
            {
                struct pp ret;
                ret.f=vec[ss].s;
                ret.s=1;
                return ret;
            }
            else return dummy;
        }
        if(ss>=qs && se<=qe) return tree[si];
        int mid=ss+((se-ss)>>1), next=(si<<1);
        struct pp aa=query(next+1,ss,mid,qs,qe), bb=query(next+2,mid+1,se,qs,qe);
        if(aa.f==bb.f){ aa.s+=bb.s; return aa; }
        else if(aa.f>bb.f) return aa;
        else return bb;
    }
    inline int bins(int i,int fl)
    {
        int l=0,r=po;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if (vec[mid].f<i) l=mid+1;
            else if (vec[mid].f>i) r=mid;
            else return mid;
        }
        return l-fl;
    }
}info[NP];
FastInput fi;
FastOutput fo;
int main()
{
    int m,i,j,k,g,co=0;
    struct pp ans;
    dummy.f=dummy.s=-1;
    n=fi.ReadNext();m=fi.ReadNext();
    fact[0][0]=fact[1][0]=0;
    for(i=2;i<MAX;i+=2) fact[i][mf[i]++]=2;
    prin[2]=co++;
    for(i=3;i<MAX;i+=2)
        if(mf[i]==0)
        {
            prin[i]=co++;
            for(j=i;j<MAX;j+=i)
                fact[j][mf[j]++]=i;
        }

    for(i=0;i<n;i++)
    {
        arr[i]=fi.ReadNext();
        for(j=0;fact[arr[i]][j];j++)
            isn[prin[fact[arr[i]][j]]]++;
    }

    for(i=0;i<m;i++)
    {
        que[i][0]=fi.ReadNext();que[i][1]=fi.ReadNext()-1;que[i][2]=fi.ReadNext()-1;
        qans[i]=dummy;
        for (j=0;fact[que[i][0]][j];j++) qins[prin[fact[que[i][0]][j]]]++;
    }

	for(i=0;i<co;i++)
		if(isn[i] && qins[i])
			info[i].ini(isn[i],qins[i]);

	for(i=0;i<n;i++)
    {
        ans.f=i;
        ans.s=arr[i];
        for(j=0;fact[arr[i]][j];j++)
            if(qins[prin[fact[arr[i]][j]]])
                info[prin[fact[arr[i]][j]]].vec[info[prin[fact[arr[i]][j]]].po++]=ans;
    }

	for(i=0;i<m;i++)
		for(j=0;fact[que[i][0]][j];j++)
			if(isn[prin[fact[que[i][0]][j]]])
				info[prin[fact[que[i][0]][j]]].qr[info[prin[fact[que[i][0]][j]]].qp++]=i;

	for(i=0;i<co;i++)
        if(isn[i] && qins[i])
        {
            info[i].init(0,0,info[i].po-1);
            info[i].queit();
        }
	for(i=0;i<m;i++)
    {
        if(qans[i].f==-1)
        {
            fo.PrintChar('-');fo.PrintChar('1');fo.PrintChar(' ');fo.PrintChar('-');fo.PrintChar('1');
            fo.PrintChar('\n');
        }
        else
        {
            fo.PrintUint(qans[i].f,' ');
            fo.PrintUint(qans[i].s,'\n');
        }
    }
    fo.Flush();
    return 0;
}
