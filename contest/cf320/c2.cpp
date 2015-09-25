#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
const double E = exp(1.0);
const double INF = 1e30;

//double maxx = -INF, minn = INF;

const int N = 200000 + 5;

double x[N];

double sqr(double x) {
    return x * x;
}

double fun(double v, int n) {
	double tmp = x[0] - v, ret = x[0] - v;
	//cout<<x[0] - v<<' ';
	bool flag = 0;
	if(x[0] < v) flag = 1;
	for(int i = 1; i < n; ++i) {
		if(x[i] < v) flag = 1;
		tmp += x[i] - v;
		//cout<<x[i] - v<<' ';
		if(tmp < x[i] - v) {
			tmp = x[i] - v;
		}
		ret = max(tmp, ret);
	}
	//cout<<endl;
	//cout<<ret<<endl;
	if(flag) {
		tmp = v - x[0];
		for(int i = 1; i < n; ++i) {
			tmp += v - x[i];
			if(tmp < v - x[i]) {
				tmp = v - x[i];
			}
			ret = max(tmp, ret);
		}
	}
	return ret;
}

int main() {
    int n;
    cin>>n;
    double x0 = 0;
    for(int i = 0; i < n; ++i) {
        cin>>x[i];
        x0 += x[i];
        //maxx = max(x[i], maxx);
        //minn = min(x[i], minn);
    }
    x0 /= n;
    int limit = 20000;
    double ans = fun(x0, n);
    double temp = 1e5; //��ʼ�¶�, ������Ŀ�޸�
    while (temp > 0.0000001) { //0.02Ϊ�¶ȵ�����, ���¶�temp�ﵽ����, ��ֹͣ����
        double X = 0;
        for (int i = 0; i < n; ++i) { //��ȡ�����Ĺ��������Ŀ����, �����������һ����Ա��ſ�
            X += (x[i] - x0);
        }
        double tmp = fun(X, n); //�꺯��E(x_new);
        if (tmp < ans) {
            ans = tmp;
            x0 += X * temp;
        } else if (pow(E, (ans - tmp) / temp) > (rand() % limit) / (double)limit) {
            ans = tmp;
            x0 += X * temp;
        }
        temp *= 0.9; //0.9Ϊ�����˻�����, (��ΧΪ0~1, Խ��õ�ȫ�����Ž�ĸ���Խ��, ����ʱ��Խ��
    }
    cout<<x0<<endl;
    printf("%.7f\n", fun(x0, n));
}
