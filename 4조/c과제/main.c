#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define MAX 256

/* 4��
    //202068019 ���ٺ� //202068021 ����� //202068023 ������ //202068025 �̼���
                                   (�Ѱ�)
*/

struct start //202068021 �����
{
    char ctgr[100]; //ī�װ� ex�ѽ�, �߽� ...
    int money; // ���ݴ� ����
};

void strcmpp(const char* x[], char* y);         //202068021 ����� - �޴� ������ �� �����ϸ� "������ ����: �޴�" ����

static int wallet(int plus, int minus);         //202068021 ����� - ����

void receipt(const char* food);                 //202068019 ���ٺ�, 202068021 �����  - ������

void printmenu(int ctgr, int mn, int random);   //202068025 �̼���, 202068021 �����    - foodrecmd�� �ִ� random ���� �޾Ƽ� �Ŵ� ����

int foodrecmd(const char* x[], struct start p); //202068025 �̼���   -  ī�װ� ������ �޴� ���ݸ� ����


static int twallet; // ���������� ���� ��� ����

int main()  //202068023 ������ ui ���, ���� ����
            //202068021 ����� ���� ����, ���� ����

{

    system("title ������ ��õ���");
    system("mode con: cols=50 lines=30");
    const char* food[5] = { "�+��","����+������","��","�����","��Ÿ" };
    struct start chos; // chos ��� start����ü ���� (ī�װ��� ���ݴ�)
    int wc = 0;

    system("color 0");
    system("color 04");//�ܼ�â ��������
    printf("----------������ �ȳ�----------\n\n**������ ������ �������� ���� ��ų ��**\n\n");
    printf("���� : 4��\n\n");
    system("pause");
    int j = 0;
    Sleep(400);
    printf("\n�ʱ�ȭ��");
    while (j < 4)
    {                  //������...
        Sleep(200);
        printf(".");
        j++;
    }
    system("cls");

    system("color 07");

    printf("�ѤѤѤѤѤѤ�------------------------------------\n");
    printf("������ ����\n");
    printf("�ѤѤѤѤѤѤ�------------------------------------\n");
    printf("����� ���ɸ޴��� ��õ�帮�ڽ��ϴ�.\n\n");
    printf("���� ���� �ݾ��� �Է����ּ���.\n");
    printf(":");

    scanf("%d", &wc); // �ʱ� �ں���
    twallet = wallet(wc, NULL); // twallet = wc

    system("cls");

    while (1)
    {
        system("color 0E");

        printf("���� ���� : %d��\n", twallet);
        printf("����������������������������������������������������\n");
        printf("��     ��  ��  ��  õ     ��\n");
        printf("��                        ��\n");
        printf("��                        ��\n");
        printf("��    ���+��           ��\n");
        printf("��                        ��\n");
        printf("��    �赤��+������       ��\n");
        printf("��                        ��\n");
        printf("��    ���                ��\n");
        printf("��                        ��\n");
        printf("��    �갣���            ��\n");
        printf("��                        ��\n");
        printf("��    ���Ÿ              ��\n");
        printf("��                        ��\n");
        printf("����������������������������������������������������\n");
        printf("���ϴ� ������ �Է����ּ���\n");
        do {
            scanf("%s", &chos.ctgr); //chos.ctgr �޴� ī�װ� ����
            fflush(stdin); //scanf �����ȶ߰� �ϴ� �ڵ�
            if (strcmp(food[0], chos.ctgr) != 0)
                printf("\n�ٽ� �Է����ּ���\n");
        } while (strcmp(food[0], chos.ctgr) != 0 && strcmp(food[1], chos.ctgr) != 0 && strcmp(food[2], chos.ctgr) != 0
            && strcmp(food[3], chos.ctgr) != 0 && strcmp(food[4], chos.ctgr) != 0
            && strcmp("1", chos.ctgr) != 0 && strcmp("2", chos.ctgr) != 0 && strcmp("3", chos.ctgr) != 0 && strcmp("4", chos.ctgr) != 0
            && strcmp("5", chos.ctgr) != 0);
        system("cls");
        system("color 01");
        printf("������������������������������������������������������������������������\n");
        printf("�� ����Ͻô� ���ݴ븦 �Է����ּ��� ��\n");
        printf("������������������������������������������������������������������������\n");
        printf("�ڰ��ݴ�� :");

        scanf("%d", &chos.money); // chos. money ���ݴ� ����
        fflush(stdin);


        system("cls"); //�ܼ�â �����

        strcmpp(food, chos.ctgr); //�Է��� ī�װ��� �������� �Ǵ�

        int i = 0;
        Sleep(400);
        printf("\n������");
        while (i < 4)
        {                  //������...
            Sleep(800);
            printf(".");
            i++;
        }
        system("cls");

        twallet = foodrecmd(food, chos); //������ �޴��� ������ ������ �ݿ� foodrecmd(�޴���, �޴� ����)
        printf("���� �����ݾ�:%d��\n\n", twallet);

        char finall[6];
        printf("����� '����' �ٽ��ϱ�� '�ٽ�'\n �Է� :");
        do {
            scanf("%s", finall);
            fflush(stdin);
            if (strcmp(finall, "����") != 0 || strcmp(finall, "�ٽ�") != 0)
                printf("\n�ٽ� �Է����ּ���\n");
        } while (strcmp(finall, "����") != 0 && strcmp(finall, "�ٽ�") != 0);
        system("cls");
        
        if (strcmp(finall, "����") == 0)
        {
            int i = 0;
            Sleep(400);
            printf("\n������ �����");
            while (i < 4)            //������...
            {
                Sleep(800);
                printf(".");
                i++;
            }
            FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\������.txt", "at");
            fprintf(recpt, "\n\n*���� : %d\n\n\n", (wc - twallet));
            fclose(recpt);
            printf("\n��� �Ϸ�.\n\n");

            fopen("C:\\Users\\Public\\Desktop\\������.txt", "rt");
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
        else if (strcmp(finall, "�ٽ�") == 0)
        {
            if (twallet - 1 < 0)
            {
                printf("���� �����մϴ�.\n���α׷��� �����մϴ�.");
                int i = 0;
                Sleep(400);
                printf("\n������ �����");
                while (i < 4)            //������...
                {
                    Sleep(800);
                    printf(".");
                    i++;
                }
                FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\������.txt", "at");
                fprintf(recpt, "\n\n*���� : %d", (wc - twallet));
                fclose(recpt);
                printf("\n��� �Ϸ�.\n\n");

                fopen("C:\\Users\\Public\\Desktop\\������.txt", "rt");
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

static int wallet(int plus, int minus) //202068021 ����� ����
{
    static int wallet = 0;

    return(wallet = wallet + plus - minus);
}

void strcmpp(const char* x[], char* y)  //202068021 ����� ����
{
    if (strcmp(x[0], y) == 0 || strcmp(y,"1")==0) //�+��
    {
        printf("������ ���� ī�װ� : ");
        puts(x[0]);
    }
    else if (strcmp(x[1], y) == 0 || strcmp(y, "2") == 0) //����+������
    {
        printf("������ ���� ī�װ� : ");
        printf(x[1]);
    }
    else if (strcmp(x[2], y) == 0 || strcmp(y, "3") == 0) //��
    {
        printf("������ ���� ī�װ� : ");
        printf(x[2]);
    }
    else if (strcmp(x[3], y) == 0 || strcmp(y, "4") == 0) //�����
    {
        printf("������ ���� ī�װ� : ");
        printf(x[3]);
    }
    else if (strcmp(x[4], y) == 0 || strcmp(y, "5") == 0) //��Ÿ
    {
        printf("������ ���� ī�װ� : ");
        printf(x[4]);
    }
}

int foodrecmd(const char* x[], struct start p) //202068025 �̼��� ��� ����
                                               //202068021 ����� ���� ���� ����, ���� ����
                                               //202068023 ������ ���� ����
{
    srand((unsigned)time(NULL));
    int random;
    int i;                            //���� �� ����
    for (i = 0; i < 5; i++)
    {
        random = (rand() % 5);
    }

    if (strcmp(x[0], p.ctgr) == 0 || strcmp(p.ctgr,"1") == 0) //ī�װ��� "�+��"�϶�
    {
        printmenu(0, p.money, random); // ���� ���� �޾Ƽ� �޴� ��� printmenu(�+��, ���ݴ�, ������)

        if ((p.money >= 0) && (p.money <= 6500)) //���ݴ밡 0~6500�� �϶�
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
        if ((p.money > 6500) && (p.money <= 8000)) //���ݴ밡 6500~8000�� �϶�
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
    else if (strcmp(x[1], p.ctgr) == 0 || strcmp(p.ctgr, "2") == 0) //ī�װ��� "����+������"�϶�
    {
        printmenu(1, p.money, random);   // printmenu(����+������, ���ݴ�, ������)

        if ((p.money >= 0) && (p.money <= 6000)) //���ݴ밡 0~6000�� �϶�
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
        if ((p.money > 6000) && (p.money <= 10000)) //���ݴ밡 6000~10000�� �϶�
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
    else if (strcmp(x[2], p.ctgr) == 0 || strcmp(p.ctgr, "3") == 0) //ī�װ��� "��"�϶�
    {
        printmenu(2, p.money, random);   // printmenu(��, ���ݴ�, ������)

        if ((p.money >= 0) && (p.money <= 6000)) //���ݴ밡 0~6000�� �϶�
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
        if ((p.money > 6000) && (p.money <= 9000)) //���ݴ밡 6000~9000�� �϶�
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
    else if (strcmp(x[3], p.ctgr) == 0 || strcmp(p.ctgr, "4") == 0) //ī�װ��� "�����"�϶�
    {
        printmenu(3, p.money, random);   // printmenu(�����, ���ݴ�, ������)

        if ((p.money >= 0) && (p.money <= 5500)) //���ݴ밡 0~5500�� �϶�
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
    else if (strcmp(x[4], p.ctgr) == 0 || strcmp(p.ctgr, "5") == 0) //ī�װ��� "��Ÿ"�϶�
    {
        printmenu(4, p.money, random);   // printmenu(��Ÿ, ���ݴ�, ������)

        if ((p.money >= 0) && (p.money <= 12500)) //���ݴ밡 0~12500�� �϶�
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

void receipt(const char* food)      //202068019 ���ٺ� ��� ����
                                     //202068021 ����� ���� ���� ����
{
    FILE* recpt = fopen("C:\\Users\\Public\\Desktop\\������.txt", "at"); // ������ ����
    fprintf(recpt, "-----------------\n");
    fputs(food, recpt);
    fprintf(recpt, "\n");
    fclose(recpt);
}

void printmenu(int ctgr, int mn, int random)     //202068025 �̼��� ��簳��
                                                 //202068021 ����� ���� ���� ����, ���װ���
{
    if (ctgr == 0) // ī�װ���  0 = �+�� �϶�
    {
        if ((mn >= 0) && (mn <= 6500)) // ���ݴ�
        {
            const char* krfood[5] = { "����� 5500��","��ġ� 5500��","�δ�� 6000��","���κ�� 5500��","�ᳪ������ 6000��" }; // 6500�� �̸��� ����

            if (random == 0)    // ������ 0 �̸� krfood[0] ���
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }

        }
        else if ((mn > 6500) && (mn <= 8000))
        {
            const char* krfood[5] = { "������ 6500��","������ 8000��","���뱹�� 6500��", "�߰��� 7000��","«���� 6500��" }; // 8000�� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", krfood[random]);
                receipt(krfood[random]);
            }
        }
    }

    else if (ctgr == 1) // ī�װ���  1 = ����+������ �϶�
    {
        if ((mn >= 0) && (mn <= 6000))
        {
            const char* chfood[5] = { "ī�� 5000��","����� 5500��","���Ƕ��̽� 5500��","�������� 5500��","��ġ����� 5500��" }; // 6000 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
        else if ((mn > 6000) && (mn <= 10000))
        {
            const char* chfood[5] = { "��ġ������ 6000��","������������ 6000��","����� 8500��", "�ٵ� 10000��","�ҺҰ�ⵤ�� 7000��" }; // 10000 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 2) // ī�װ���  2 = �� �϶�
    {
        if ((mn >= 0) && (mn <= 6000))
        {
            const char* chfood[5] = { "��� 5500��","��ġ���� 5000��","������� 5500��","�̸� 5000��","Į���� 5500��" }; // 6000 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
        else if ((mn > 6000) && (mn <= 9000))
        {
            const char* chfood[5] = { "�ø� 6000��","�Ľ�Ÿ 9000��","�쵿 6000��", "¥��� 6000��","«�� 6500��" }; // 9000 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 3) // ī�װ���  3 = ����� �϶�
    {
        if ((mn >= 0) && (mn <= 5500))
        {
            const char* chfood[5] = { "������ġ 4500��","������ 4000��","������ 4000��","���ö� 5000��","��� 3000��" }; // 5500 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }

    else if (ctgr == 4) // ī�װ���  4 = ��Ÿ �϶�
    {
        if ((mn >= 0) && (mn <= 12500))
        {
            const char* chfood[5] = { "�ʹ� 12000��","���� 4500��","���� 10000��","��� 8000��","������ũ 12000��" }; // 12500 �� �̸��� ����

            if (random == 0)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 1)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 2)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 3)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
            else if (random == 4)
            {
                printf("��õ ����: %s\n", chfood[random]);
                receipt(chfood[random]);
            }
        }
    }
}
