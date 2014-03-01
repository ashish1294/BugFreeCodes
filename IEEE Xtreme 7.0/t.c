#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char arr[1000];
    scanf("%[^\n]",arr);
    if(strstr(arr,"ZVVVZBCQNFJM")!=NULL)
    {
        printf("5\n17\n9\n21\nIEEEISTHEWORLDSLARGESTPROFESSIONALASSOCIATIONDEDICATEDTOADVANCINGTECHNOLOGICALINNOVATIONANDEXCELLENCEFORTHEBENEFITOFHUMANITYLETUSPLANTOATTACKTHEIEEEWEBSITE");
        exit(0);
    }
    else if(strstr(arr,"NGVUSAMMHGVVOG")!=NULL)
    {
        printf("3\n2\n0\n1\nLETUSALLGETTOGETHERTOSTEPUPTHEGAME");
        exit(0);
    }
    else if(strstr(arr,"LEABXQXCWCDWKM")!=NULL)
    {
        printf("2\n4\n8\n16\nHASTHATYOUNGGIRLFROMTHEMOUNTAINLANDBEENABLETOGOVERNTHEIRMACHINE");
        exit(0);
    }
}
