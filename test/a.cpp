/*��⣺
  �����ַ������Ȳ�����100�������ֵ�����������100�����Կ��Ա����жϣ��ж�һ���ʱ�临�Ӷ�Ϊ100 * 100��Ȼ��100���ʱ�临�Ӷ�Ϊ1e6����1s��ʱ���ڿ��Խ����
  ���ж��ں��Դ�Сд��ѡ�ֻҪͳһת��ΪСд�ַ��жϼ��ɡ�
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

char word[N];
char text[N];

//���ַ�������ַ�ͳһת����Сд��
void to_lowercase(char *str) {
	int len = strlen(str);
	for(int i = 0; i < len; ++i) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

//�ж��ַ���text�Ƿ�����ַ���word
bool ok(char *text, int op) {
	char tmp[N];
	int text_len = strlen(text);
	for(int i = 0; i < text_len; ++i) {
		tmp[i] = text[i];
	}
	if(op == 0) to_lowercase(tmp);	//�ж��Ƿ�Ҫ���Դ�Сд

	//�жϰ�����ϵ
	int word_len = strlen(word);
	for(int i = 0; i <= text_len - word_len; ++i) {
		int flag = 1;
		for(int j = 0; j < word_len; ++j) {
			if(word[j] != tmp[i + j]) {
				flag = 0;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}

int main() {
	int op, n;
	scanf("%s", word);
	scanf("%d", &op);
	scanf("%d", &n);

	if(op == 0) to_lowercase(word);	//�ж��Ƿ�Ҫ���Դ�Сд

	for(int i = 0; i < n; ++i) {
		scanf("%s", text);
		if(ok(text, op)) {
			printf("%s\n", text);
		}
	}
	return 0;
}
