/*
���⣺
    ��һ����ά�ռ��У�����һЩ�㣬��Щ���z���궼�Ǵ���0�ġ�Ҫ����
��һ��Բ׶��������Բ�Σ���ʹ�����Բ׶�ĵ�����z = 0��ƽ���ϣ����ܹ�
�������и����ĵ㲢��Բ׶�����Ҫ����С��

��⣺
    ��ѧ�Ƶ� + ����

˼·��
    ����һ��������˼���⣬��Ȼ����ά�ģ����ǿ��Ժ����׵�ת������άȥ
������X-Z���ƽ�棬���ǽ����еĵ����Բ��ӳ�䣬Ȼ�����еĵ㶼ͶӰ��
X-Zƽ��ĵĵ�һ����ȥ��Ȼ�������ת��������X-Zƽ�����ҵ�һ��б��Ϊ��
��ֱ��L��L��X������Z������Χ�ɵ������ΰ������е㣬�������L��X���
����ΪR����Z�ό��ΪH��Ҫ��pi*H*R^2��ֵ��С��
    Ȼ������������H��R֮����ʲôǧ˿���ƵĹ�ϵ������L�����߱ض���ĳһ
�������ĵ���ߣ�Ҳ���Ǿ����Ǹ��㣬���Ǽ���������P(a, b)�� ����L��б��
ΪK(K < 0)����ôL�ķ��̾Ϳ��Ա�ʾΪ L:  y = K * (x - a) + b����H��R��
��������������̱�ʾ������
H = -a * K + b;
R = -b / K + a;
��ô�����Բ׶��������ǣ�
V = pi*H*R^2 = pi * (-a * K + b) * (-b / K + a) ^ 2
���׵õ�V(K)��������ĵ�����
V'(K) = - pi * (aK^2 + 2bK) * (aK - b)^2 / K^2
Ӱ����������������Ե�Ψһ������ -(aK^2 + 2bK)
��-2b/a < K < 0ʱV'(K)�����㣬Ҳ����V��ֵ������K�����ġ�
��K < -2b/aʱV'(K)С���㣬Ҳ����V��ֵ������K�ݼ��ġ�
���ǿ��Եó�һ�����ۣ���K = -2b/a ʱVȡ����Сֵ��
��������֪����V�ĵ����ԣ�Ȼ��Ϳ���ͨ��ö�ٰ뾶R����ΪR����V���е���
�ԣ�����ö��R��ʱ����Բ������֡�ÿ��ͨ������R�ҵ���С��H��������̿�
��ͨ��ö��ÿ���㣬�ҵ����ļ���alpha��R*tan(alpha)����H�ˡ�
    ������Ҫע��ľ��Ǿ��������ˡ�
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define eps 1e-6
const double pi = acos(-1.0);

struct Point {
    double x, y, z;
    double v, h;

    void SCANF() {
        scanf("%lf %lf %lf", &x, &y, &z);
        v = z;
        h = sqrt(x*x + y*y);
    }
}pt[ 10001 ];

int n;
double MaxH, MaxV;

double Calc(double R) {
    int i;
    double Max = 0;
    int idx = 0;
    for(i = 0; i < n; i++) {
        double nv = pt[i].v / (R - pt[i].h);
        if(nv > Max) {
            Max = nv;
            idx = i;
        }
    }
    return Max * R;
}

int main() {
    int t;
    int i;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        MaxH = MaxV = 0;
        for(i = 0; i < n; i++) {
            pt[i].SCANF();
            if(pt[i].h > MaxH)
                MaxH = pt[i].h;
            if(pt[i].v > MaxV)
                MaxV = pt[i].v;
        }

        double l = MaxH + eps, r = 1e6;
        double ml, mr;

        while(l + 1e-6 < r) {
            ml = (2 * l + r) / 3;
            mr = (l + 2 * r) / 3;

            double lans = Calc(ml) * ml * ml;
            double rans = Calc(mr) * mr * mr;

            if( lans > rans ) {
                l = ml + 1e-5;
            }else
                r = mr - 1e-5;
        }
        double ans = (l + r) / 2;
        printf("%.3lf %.3lf\n", Calc(ans), ans);
    }
    return 0;
}
