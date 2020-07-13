#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // fopen, feof, fread, fclose 함수가 선언된 헤더 파일
#include <string.h>    // strlen, memset 함수가 선언된 헤더 파일
#include <stdint.h>
#include <netinet/in.h>
int is_little_endian()
{
 int a = 0x01234567;
 if ( *((char*)&a) == 0x67 )
 {
  return 1; // little endian
 }
 return 0; //big endian
}
int main(int argc,char *argv[])
{
    if(argc <3) {
        printf("Usage : %s <filename1> <filename2>\n", argv[0]);
        return 0;
    }

    char buffer1[4];    // 문자열 데이터 4바이트
    char buffer2[4];
    uint32_t n1,n2,n3;

    FILE *fp = fopen(argv[1], "r");
    fread(buffer1, sizeof(char), 4, fp);    // 1바이트씩 4번(4바이트) 읽기
    uint32_t *a = reinterpret_cast<uint32_t*>(buffer1);

    FILE *fp2 = fopen(argv[2], "r");
    fread(buffer2, sizeof(char), 4, fp2);    // 1바이트씩 4번(4바이트) 읽기
    uint32_t *a2 = reinterpret_cast<uint32_t*>(buffer2);

    if(is_little_endian() == 1){
        n1 = ntohl(*a);
        n2 = ntohl(*a2);
        n3 = n1 + n2;
    }else{
        n3 = n1 + n2;
    }

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,n3,n3);
    fclose(fp);    // 파일 포인터 닫기
    fclose(fp2);

    return 0;
}
