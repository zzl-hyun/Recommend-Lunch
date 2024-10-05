#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define MAX 256

/* 4조
    //202068019 유다빈 //202068021 김기현 //202068023 최지훈 //202068025 이서원
                                   (총괄)
*/

struct start //202068021 김기현
{
    char ctgr[100]; //카테고리 ex한식, 중식 ...
    int money; // 가격대 설정
};

void strcmpp(const char* x[], char* y);         //202068021 김기현 - 메뉴 선택할 때 선택하면 "선택한 음식: 메뉴" 도출

static int wallet(int plus, int minus);         //202068021 김기현 - 지갑

void receipt(const char* food);                 //202068019 유다빈, 202068021 김기현  - 영수증

void printmenu(int ctgr, int mn, int random);   //202068025 이서원, 202068021 김기현    - foodrecmd에 있는 random 값을 받아서 매뉴 도출

int foodrecmd(const char* x[], struct start p); //202068025 이서원   -  카테고리 설정후 메뉴 가격만 전달


static int twallet; // 고정변수로 지갑 계속 유지

int main()  //202068023 최지훈 ui 담당, 버그 개선
            //202068021 김기현 뼈대 제작, 버그 개선

{

    system("title ◎점심 추천기◎");
    system("mode con: cols=50 lines=30");
    const char* food[5] = { "찌개+탕","덮밥+볶음밥","면","간편식","기타" };
    struct start chos; // chos 라는 start구조체 선언 (카테고리와 가격대)
    int wc = 0;

    system("color 0");
    system("color 04");//콘솔창 검정으로
    printf("----------실행전 안내----------\n\n**파일을 관리자 권한으로 실행 시킬 것**\n\n");
    printf("제작 : 4조\n\n");
    system("pause");
    int j = 0;
    Sleep(400);
    printf("\n초기화중");
    while (j < 4)
    {                  //설정중...
        Sleep(200);
        printf(".");
        j++;
    }
    system("cls");

    system("color 07");

    printf("ㅡㅡㅡㅡㅡㅡㅡ------------------------------------\n");
    printf("오늘의 점심\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡ------------------------------------\n");
    printf("당신의 점심메뉴를 추천드리겠습니다.\n\n");
    printf("현재 가진 금액을 입력해주세요.\n");
    printf(":");

    scanf("%d", &wc); // 초기 자본값
    twallet = wallet(wc, NULL); // twallet = wc

    system("cls");

    while (1)
    {
        system("color 0E");

        printf("현재 지갑 : %d원\n", twallet);
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃     메  뉴  추  천     ┃\n");
        printf("┃                        ┃\n");
        printf("┃                        ┃\n");
        printf("┃    ①찌개+탕           ┃\n");
        printf("┃                        ┃\n");
        printf("┃    ②덮밥+볶음밥       ┃\n");
        printf("┃                        ┃\n");
        printf("┃    ③면                ┃\n");
        printf("┃                        ┃\n");
        printf("┃    ④간편식            ┃\n");
        printf("┃                        ┃\n");
        printf("┃    ⑤기타              ┃\n");
        printf("┃                        ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("원하는 음식을 입력해주세요\n");
        do {
            scanf("%s", &chos.ctgr); //chos.ctgr 메뉴 카테고리 설정
            fflush(stdin); //scanf 오류안뜨게 하는 코드
            if (strcmp(food[0], chos.ctgr) != 0)
                printf("\n다시 입력해주세요\n");
        } while (strcmp(food[0], chos.ctgr) != 0 && strcmp(food[1], chos.ctgr) != 0 && strcmp(food[2], chos.ctgr) != 0
            && strcmp(food[3], chos.ctgr) != 0 && strcmp(food[4], chos.ctgr) != 0
            && strcmp("1", chos.ctgr) != 0 && strcmp("2", chos.ctgr) != 0 && strcmp("3", chos.ctgr) != 0 && strcmp("4", chos.ctgr) != 0
            && strcmp("5", chos.ctgr) != 0);
        system("cls");
        system("color 01");
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃ 희망하시는 가격대를 입력해주세요 ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("★가격대★ :");

        scanf("%d", &chos.money); // chos. money 가격대 설정
        fflush(stdin);


        system("cls"); //콘솔창 지우기

        strcmpp(food, chos.ctgr); //입력한 카테고리가 무엇인지 판단

        int i = 0;
        Sleep(400);
        printf("\n설정중");
        while (i < 4)
        {                  //설정중...
            Sleep(800);
            printf(".");
            i++;
        }
        system("cls");

        twallet = foodrecmd(food, chos); //설정된 메뉴의 가격을 지갑에 반영 foodrecmd(메뉴판, 메뉴 선택)
        printf("현재 보유금액:%d원\n\n", twallet);

        char finall[6];
        printf("종료는 '종료' 다시하기는 '다시'\n 입력 :");
        do {
            scanf("%s", finall);
            fflush(stdin);
            if (strcmp(finall, "종료") != 0 || strcmp(finall, "다시") != 0)
                printf("\n다시 입력해주세요\n");
        } while (strcmp(finall, "종료") != 0 && strcmp(finall, "다시") != 0);
        system("cls");
        
        if (strcmp(finall, "종료") == 0)
        {
            int i = 0;
            Sleep(400);
            printf("\n영수증 출력중");
            while (i < 4)            //설정중...
            {
                Sleep(800);
                printf(".");
                i++;
            }
            FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\영수증.txt", "at");
            fprintf(recpt, "\n\n*가격 : %d\n\n\n", (wc - twallet));
            fclose(recpt);
            printf("\n출력 완료.\n\n");

            fopen("C:\\Users\\Public\\Desktop\\영수증.txt", "rt");
            while (feof(recpt) == 0)
            {
                char buffer[MAX];
                fgets(buffer, MAX, recpt);
                printf("%s", buffer);
            }
            fclose(recpt);

            system("pause");
            break;

        }
        else if (strcmp(finall, "다시") == 0)
        {
            if (twallet - 1 < 0)
            {
                printf("돈이 부족합니다.\n프로그램을 종료합니다.");
                int i = 0;
                Sleep(400);
                printf("\n영수증 출력중");
                while (i < 4)            //설정중...
                {
                    Sleep(800);
                    printf(".");
                    i++;
                }
                FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\영수증.txt", "at");
                fprintf(recpt, "\n\n*가격 : %d", (wc - twallet));
                fclose(recpt);
                printf("\n출력 완료.\n\n");

                fopen("C:\\Users\\Public\\Desktop\\영수증.txt", "rt");
                while (feof(recpt) == 0)
                {
                    char buffer[MAX];
                    fgets(buffer, MAX, recpt);
                    printf("%s", buffer);
                }
                fclose(recpt);

                system("pause");
                break;
            }

            system("cls");
            continue;

        }
    }
}

static int wallet(int plus, int minus) //202068021 김기현 개발
{
    static int wallet = 0;

    return(wallet = wallet + plus - minus);
}

void strcmpp(const char* x[], char* y)  //202068021 김기현 개발
{
    if (strcmp(x[0], y) == 0 || strcmp(y,"1")==0) //찌개+탕
    {
        printf("선택한 음식 카테고리 : ");
        puts(x[0]);
    }
    else if (strcmp(x[1], y) == 0 || strcmp(y, "2") == 0) //덮밥+볶음밥
    {
        printf("선택한 음식 카테고리 : ");
        printf(x[1]);
    }
    else if (strcmp(x[2], y) == 0 || strcmp(y, "3") == 0) //면
    {
        printf("선택한 음식 카테고리 : ");
        printf(x[2]);
    }
    else if (strcmp(x[3], y) == 0 || strcmp(y, "4") == 0) //간편식
    {
        printf("선택한 음식 카테고리 : ");
        printf(x[3]);
    }
    else if (strcmp(x[4], y) == 0 || strcmp(y, "5") == 0) //기타
    {
        printf("선택한 음식 카테고리 : ");
        printf(x[4]);
    }
}

int foodrecmd(const char* x[], struct start p) //202068025 이서원 담당 개발
                                               //202068021 김기현 기초 뼈대 제작, 버그 개선
                                               //202068023 최지훈 버그 개선
{
    srand((unsigned)time(NULL));
    int random;
    int i;                            //랜덤 값 설정
    for (i = 0; i < 5; i++)
    {
        random = (rand() % 5);
    }

    if (strcmp(x[0], p.ctgr) == 0 || strcmp(p.ctgr,"1") == 0) //카테고리가 "찌개+탕"일때
    {
        printmenu(0, p.money, random); // 랜덤 값을 받아서 메뉴 출력 printmenu(찌개+탕, 가격대, 랜덤값)

        if ((p.money >= 0) && (p.money <= 6500)) //가격대가 0~6500원 일때
        {
            if (random == 0)
                return (wallet(0, 5500));
            else if (random == 1)
                return (wallet(0, 5500));
            else if (random == 2)
                return (wallet(0, 6000));
            else if (random == 3)
                return (wallet(0, 5500));
            else if (random == 4)
                return (wallet(0, 6000));
        }
        if ((p.money > 6500) && (p.money <= 8000)) //가격대가 6500~8000원 일때
        {
            if (random == 0)
                return (wallet(0, 6500));
            else if (random == 1)
                return (wallet(0, 8000));
            else if (random == 2)
                return (wallet(0, 6500));
            else if (random == 3)
                return (wallet(0, 7000));
            else if (random == 4)
                return (wallet(0, 6500));
        }
    }
    else if (strcmp(x[1], p.ctgr) == 0 || strcmp(p.ctgr, "2") == 0) //카테고리가 "덮밥+볶음밥"일때
    {
        printmenu(1, p.money, random);   // printmenu(덮밥+볶음밥, 가격대, 랜덤값)

        if ((p.money >= 0) && (p.money <= 6000)) //가격대가 0~6000원 일때
        {

            if (random == 0)
                return (wallet(0, 5000));
            else if (random == 1)
                return (wallet(0, 5500));
            else if (random == 2)
                return (wallet(0, 5500));
            else if (random == 3)
                return (wallet(0, 5500));
            else if (random == 4)
                return (wallet(0, 5500));
        }
        if ((p.money > 6000) && (p.money <= 10000)) //가격대가 6000~10000원 일때
        {

            if (random == 0)
                return (wallet(0, 6000));
            else if (random == 1)
                return (wallet(0, 6000));
            else if (random == 2)
                return (wallet(0, 8500));
            else if (random == 3)
                return (wallet(0, 10000));
            else if (random == 4)
                return (wallet(0, 7000));
        }
    }
    else if (strcmp(x[2], p.ctgr) == 0 || strcmp(p.ctgr, "3") == 0) //카테고리가 "면"일때
    {
        printmenu(2, p.money, random);   // printmenu(면, 가격대, 랜덤값)

        if ((p.money >= 0) && (p.money <= 6000)) //가격대가 0~6000원 일때
        {

            if (random == 0)
                return (wallet(0, 5500));
            else if (random == 1)
                return (wallet(0, 5000));
            else if (random == 2)
                return (wallet(0, 5500));
            else if (random == 3)
                return (wallet(0, 5000));
            else if (random == 4)
                return (wallet(0, 5500));
        }
        if ((p.money > 6000) && (p.money <= 9000)) //가격대가 6000~9000원 일때
        {

            if (random == 0)
                return (wallet(0, 6000));
            else if (random == 1)
                return (wallet(0, 9000));
            else if (random == 2)
                return (wallet(0, 6000));
            else if (random == 3)
                return (wallet(0, 6000));
            else if (random == 4)
                return (wallet(0, 6500));
        }
        return 0;
    }
    else if (strcmp(x[3], p.ctgr) == 0 || strcmp(p.ctgr, "4") == 0) //카테고리가 "간편식"일때
    {
        printmenu(3, p.money, random);   // printmenu(간편식, 가격대, 랜덤값)

        if ((p.money >= 0) && (p.money <= 5500)) //가격대가 0~5500원 일때
        {

            if (random == 0)
                return (wallet(0, 4500));
            else if (random == 1)
                return (wallet(0, 4000));
            else if (random == 2)
                return (wallet(0, 4000));
            else if (random == 3)
                return (wallet(0, 5000));
            else if (random == 4)
                return (wallet(0, 3000));
        }
        return 0;
    }
    else if (strcmp(x[4], p.ctgr) == 0 || strcmp(p.ctgr, "5") == 0) //카테고리가 "기타"일때
    {
        printmenu(4, p.money, random);   // printmenu(기타, 가격대, 랜덤값)

        if ((p.money >= 0) && (p.money <= 12500)) //가격대가 0~12500원 일때
        {

            if (random == 0)
                return (wallet(0, 12000));
            else if (random == 1)
                return (wallet(0, 4500));
            else if (random == 2)
                return (wallet(0, 10000));
            else if (random == 3)
                return (wallet(0, 8000));
            else if (random == 4)
                return (wallet(0, 12000));
        }
        return 0;
    }
}

void receipt(const char* food)      //202068019 유다빈 담당 개발
                                     //202068021 김기현 기초 뼈대 제작
{
    FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\영수증.txt", "at"); // 영수증 제작
    fprintf(recpt, "-----------------\n");
    fputs(food, recpt);
    fprintf(recpt, "\n");
    fclose(recpt);
}

void printmenu(int ctgr, int mn, int random)     //202068025 이서원 담당개발
                                                 //202068021 김기현 기초 뼈대 제작, 버그개선
{
    if (ctgr == 0) // 카테고리가  0 = 찌개+탕 일때
    {
        if ((mn >= 0) && (mn <= 6500)) // 가격대
        {
            const char* krfood[5] = { "된장찌개 5500원","김치찌개 5500원","부대찌개 6000원","순두부찌개 5500원","콩나물국밥 6000원" }; // 6500원 미만용 음식

            if (random == 0)    // 랜덤이 0 이면 krfood[0] 출력
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }

        }
        else if ((mn > 6500) && (mn <= 8000))
        {
            const char* krfood[5] = { "육개장 6500원","갈비탕 8000원","순대국밥 6500원", "닭개장 7000원","짬뽕탕 6500원" }; // 8000원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
        }
    }

    else if (ctgr == 1) // 카테고리가  1 = 덮밥+볶음밥 일때
    {
        if ((mn >= 0) && (mn <= 6000))
        {
            const char* chfood[5] = { "카레 5000원","비빔밥 5500원","오므라이스 5500원","제육덮밥 5500원","참치비빔밥 5500원" }; // 6000 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
        else if ((mn > 6000) && (mn <= 10000))
        {
            const char* chfood[5] = { "김치볶음밥 6000원","베이컨볶음밥 6000원","연어덮밥 8500원", "텐동 10000원","소불고기덮밥 7000원" }; // 10000 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 2) // 카테고리가  2 = 면 일때
    {
        if ((mn >= 0) && (mn <= 6000))
        {
            const char* chfood[5] = { "라멘 5500원","잔치국수 5000원","비빔국수 5500원","쫄면 5000원","칼국수 5500원" }; // 6000 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
        else if ((mn > 6000) && (mn <= 9000))
        {
            const char* chfood[5] = { "냉면 6000원","파스타 9000원","우동 6000원", "짜장면 6000원","짬뽕 6500원" }; // 9000 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 3) // 카테고리가  3 = 간편식 일때
    {
        if ((mn >= 0) && (mn <= 5500))
        {
            const char* chfood[5] = { "샌드위치 4500원","떡볶이 4000원","샐러드 4000원","도시락 5000원","김밥 3000원" }; // 5500 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 4) // 카테고리가  4 = 기타 일때
    {
        if ((mn >= 0) && (mn <= 12500))
        {
            const char* chfood[5] = { "초밥 12000원","만두 4500원","삼겹살 10000원","돈까스 8000원","스테이크 12000원" }; // 12500 원 미만용 음식

            if (random == 0)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("추천 음식: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }
}
