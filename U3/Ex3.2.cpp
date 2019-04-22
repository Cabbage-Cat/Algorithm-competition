#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    char d[80+5];

    const double mass[4] = {12.01,1.008,16.00,14.01};
    
    while (t--)
    {
        double res=0;
        scanf("%s",d);
        for (int i=0;i<strlen(d);i++)
        {
            int count =0;
            double m;
            if (isalpha(d[i]))
            {
                for (int j=i+1;j<strlen(d);j++)
                {
                    if (isdigit(d[j]))
                        count = count*10 + (d[j]-'0');
                    else
                        break;
                }
                switch (d[i])
                {
                case 'C':
                    m = mass[0];
                    break;
                case 'H':
                    m = mass[1];
                    break;
                case 'O':
                    m = mass[2];
                    break;
                case 'N':
                    m = mass[3];
                default:
                    break;
                }

                if (!count)
                    res+=m;
                else
                    res+=m*count;
                
            }
                           
        }
        printf("%.3lf\n",res);
    }
    return 0;
}