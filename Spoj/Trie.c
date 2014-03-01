#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (255)
#define CHAR_TO_INDEX(c) ((int)c)

typedef struct trie_node trie_node_t;
struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

// trie ADT
typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};

// Returns new trie node (initialized to NULLs)
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode )
    {
        int i;

        pNode->value = 0;

        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pTrie->count++;
    pCrawl = pTrie->root;
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);

        if( !pCrawl->children[index] )
            return 0;
        pCrawl = pCrawl->children[index];
    }
    return (0 != pCrawl && pCrawl->value);
}
static long long int dparr[100000];
int morlen;
char str[100000];
trie_t trie;
long long int TotalStrings(int i)
{
    long long int answer=0;
    if(dparr[i]!=-1)
        return dparr[i];
    int k;
    char ttt[10001];
    strcpy(ttt,"");
	for(k=i;k<morlen;k++)
	{
        ttt[k-i]=str[k];
        ttt[k-i+1]='\0';
        //printf("\nttt=%s\n",ttt);
        if (search(&trie, ttt))
        {
            if(k==morlen-1)
                answer=1;
            else
                answer += TotalStrings(k+1);
        }
	}
	dparr[i]=answer;
    return answer;
}
int main()
{
    int t,n,i,templen,j;
    char tword[30],ttword[120];
    scanf("%d",&t);
    while(t--)
    {
        initialize(&trie);
        scanf("%s",str);
        morlen=strlen(str);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",tword);
            templen=strlen(tword);
            ttword[0]='\0';
            for(j=0;j<templen;j++)
            {
                switch(tword[j])
                {
                case 'A':strcat(ttword,".-");break;
                case 'B':strcat(ttword,"-...");break;
                case 'C':strcat(ttword,"-.-.");break;
                case 'D':strcat(ttword,"-..");break;
                case 'E':strcat(ttword,".");break;
                case 'F':strcat(ttword,"..-.");break;
                case 'G':strcat(ttword,"--.");break;
                case 'H':strcat(ttword,"....");break;
                case 'I':strcat(ttword,"..");break;
                case 'J':strcat(ttword,".---");break;
                case 'K':strcat(ttword,"-.-");break;
                case 'L':strcat(ttword,".-..");break;
                case 'M':strcat(ttword,"--");break;
                case 'N':strcat(ttword,"-.");break;
                case 'O':strcat(ttword,"---");break;
                case 'P':strcat(ttword,".--.");break;
                case 'Q':strcat(ttword,"--.-");break;
                case 'R':strcat(ttword,".-.");break;
                case 'S':strcat(ttword,"...");break;
                case 'T':strcat(ttword,"-");break;
                case 'U':strcat(ttword,"..-");break;
                case 'V':strcat(ttword,"...-");break;
                case 'W':strcat(ttword,".--");break;
                case 'X':strcat(ttword,"-..-");break;
                case 'Y':strcat(ttword,"-.--");break;
                case 'Z':strcat(ttword,"--..");break;
                }
            }
            insert(&trie, ttword);
        }
        for(j=0;j<100000;j++)
            dparr[j]=-1;
        long long int ans = TotalStrings(0);
        //printf("search=%d\n",search(&trie,".--"));
        printf("%lld\n",ans);
    }
    return 0;
}
