#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
	int stopp = 0, stop = 1;

	printf("歡迎遊玩拉霸機,您的體驗金額為5000代幣\n");   //遊戲說明
	printf("遊戲說明:\n");
	printf("輸入下注金額後將啟動拉霸機\n");
	printf("兩個相同出現獲得獎金1:5\n");
	printf("三個相同出現為頭獎1:100\n");
	printf("出現777時為特獎1:500\n");
	printf("每局結束時可選擇是否續玩\n");
	printf("最低下注金額為50\n");
	printf("餘額不足時選擇是否儲值，或退出遊戲\n");



	float q, t, area, s = 0;
	int i, bet, j, add, money=5000, a[3] = { 0 };

	while (stop == 1)
	{
		srand(time(NULL));    //取不同的亂數種子

		for (i = 0; i < 3; i++)    //取亂數
			a[i] = (rand() % 10);     


		if (money < 50)           //剩餘金額低於最低下注時
		{
			printf("\n餘額不足是否儲值?\n (輸入 1  幫我加個分我幫你加值~)\n (輸入 0 退出遊戲)\n");
			scanf_s("%d", &add);

			if (add == 1)
			{
				money = money + 5000;
				printf("已加值5000\n");
			}
			else if (add == 0)
			{
				printf("\n感謝遊玩");

				system("pause");
				return 0;
			}
			else
				printf("\n輸入錯誤\n");
		}
		else      //剩餘金額還夠的時候
		{
			printf("\n請輸入下注金額:");
			scanf_s("%d", &bet);

			if (money - bet<0)           //下注金額比剩餘金額還大時
				printf("\n餘額不足");
			else                         //下注金額比剩餘金額還小時
			{
				if (bet<50)              //下注金額低於最低下注金額時
					printf("\n低於最低下注金額\n");
				else                     //下注金額沒有問題時
				{
					printf("\n");
					for (i = 0; i < 3; i++)			//顯示出此次拉霸的結果
						printf("  %d", a[i]);
					printf("\n");


					if (a[0] == 7 && a[1] == 7 && a[2] == 7)    //結果為777時
					{
						printf("\n恭喜中特獎\n");
						printf("\n前局餘額為%d\n",money);
						printf("獲得獎金%d元", bet * 500);
						money = money + bet * 500;
						printf("\n目前餘額為%d\n", money);
					}

					else if (a[0] == a[1] && a[1] == a[2])      //結果3個相同但不為777時
					{
						printf("\n恭喜中頭獎\n");
						printf("\n前局餘額為%d\n", money);
						printf("獲得獎金%d元", bet * 100);
						money = money + bet * 100;
						printf("\n目前餘額為%d\n", money);
					}

					else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])  //結果有2個相同時
					{
						printf("\n恭喜中獎\n");
						printf("\n前局餘額為%d\n", money);
						printf("獲得獎金%d元", bet * 5);
						money = money + bet * 5;
						printf("\n目前餘額為%d\n", money);
					}
					else                                                  //沒有相同時
					{
						printf("\n可惜沒中獎QAQ\n");
						printf("\n前局餘額為%d\n", money);
						printf("扣除點數%d元", bet);
						money = money - bet;
						printf("\n目前餘額為%d\n", money);
					}

					printf("\n是否繼續遊玩?\n (輸入 1  繼續遊玩)\n (輸入 0 退出遊戲)\n");     //遊戲結束後
					scanf_s("%d", &stopp);

					if (stopp == 1)
						stop = 1;
					else if (stopp == 0)
						stop = 0;
					else
						printf("\n輸入錯誤\n");

				}
			}
		}

	}

	printf("\n感謝遊玩~\n\n");
	system("pause");
	return 0;
}