#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
	int stopp = 0, stop = 1;

	printf("�w��C�����Q��,�z��������B��5000�N��\n");   //�C������
	printf("�C������:\n");
	printf("��J�U�`���B��N�Ұʩ��Q��\n");
	printf("��ӬۦP�X�{��o����1:5\n");
	printf("�T�ӬۦP�X�{���Y��1:100\n");
	printf("�X�{777�ɬ��S��1:500\n");
	printf("�C�������ɥi��ܬO�_��\n");
	printf("�̧C�U�`���B��50\n");
	printf("�l�B�����ɿ�ܬO�_�x�ȡA�ΰh�X�C��\n");



	float q, t, area, s = 0;
	int i, bet, j, add, money=5000, a[3] = { 0 };

	while (stop == 1)
	{
		srand(time(NULL));    //�����P���üƺؤl

		for (i = 0; i < 3; i++)    //���ü�
			a[i] = (rand() % 10);     


		if (money < 50)           //�Ѿl���B�C��̧C�U�`��
		{
			printf("\n�l�B�����O�_�x��?\n (��J 1  ���ڥ[�Ӥ������A�[��~)\n (��J 0 �h�X�C��)\n");
			scanf_s("%d", &add);

			if (add == 1)
			{
				money = money + 5000;
				printf("�w�[��5000\n");
			}
			else if (add == 0)
			{
				printf("\n�P�¹C��");

				system("pause");
				return 0;
			}
			else
				printf("\n��J���~\n");
		}
		else      //�Ѿl���B�ٰ����ɭ�
		{
			printf("\n�п�J�U�`���B:");
			scanf_s("%d", &bet);

			if (money - bet<0)           //�U�`���B��Ѿl���B�٤j��
				printf("\n�l�B����");
			else                         //�U�`���B��Ѿl���B�٤p��
			{
				if (bet<50)              //�U�`���B�C��̧C�U�`���B��
					printf("\n�C��̧C�U�`���B\n");
				else                     //�U�`���B�S�����D��
				{
					printf("\n");
					for (i = 0; i < 3; i++)			//��ܥX�������Q�����G
						printf("  %d", a[i]);
					printf("\n");


					if (a[0] == 7 && a[1] == 7 && a[2] == 7)    //���G��777��
					{
						printf("\n���ߤ��S��\n");
						printf("\n�e���l�B��%d\n",money);
						printf("��o����%d��", bet * 500);
						money = money + bet * 500;
						printf("\n�ثe�l�B��%d\n", money);
					}

					else if (a[0] == a[1] && a[1] == a[2])      //���G3�ӬۦP������777��
					{
						printf("\n���ߤ��Y��\n");
						printf("\n�e���l�B��%d\n", money);
						printf("��o����%d��", bet * 100);
						money = money + bet * 100;
						printf("\n�ثe�l�B��%d\n", money);
					}

					else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])  //���G��2�ӬۦP��
					{
						printf("\n���ߤ���\n");
						printf("\n�e���l�B��%d\n", money);
						printf("��o����%d��", bet * 5);
						money = money + bet * 5;
						printf("\n�ثe�l�B��%d\n", money);
					}
					else                                                  //�S���ۦP��
					{
						printf("\n�i���S����QAQ\n");
						printf("\n�e���l�B��%d\n", money);
						printf("�����I��%d��", bet);
						money = money - bet;
						printf("\n�ثe�l�B��%d\n", money);
					}

					printf("\n�O�_�~��C��?\n (��J 1  �~��C��)\n (��J 0 �h�X�C��)\n");     //�C��������
					scanf_s("%d", &stopp);

					if (stopp == 1)
						stop = 1;
					else if (stopp == 0)
						stop = 0;
					else
						printf("\n��J���~\n");

				}
			}
		}

	}

	printf("\n�P�¹C��~\n\n");
	system("pause");
	return 0;
}