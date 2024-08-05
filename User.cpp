#include "User.h"


// ���캯��
User::User()
	: PlayerName(), account(), password(),
	Num_Of_isPassed_Level(), History_Score(),
	vip(false),
	isInitial(true),
	isAllPassed(false),
	isFirstPassed(true)
{}

// ��ȡ�������
const std::string User::get_PlayerName() {
	return std::string(PlayerName);
}

// ��ȡ�˺�
const std::string User::get_account() {
	return std::string(account);
}

// ����ͨ���Ĺؿ���
void User::set_Num_Of_isPassed_Level(int Num_Of_isPassed_Level) {
	this->Num_Of_isPassed_Level = Num_Of_isPassed_Level;
}

// ��ȡͨ���Ĺؿ���
int User::get_Num_Of_isPassed_Level() {
	return Num_Of_isPassed_Level;
}

// ���ý�����ֲ��
void User::set_vip(bool vip) {
	this->vip = vip;
}

// ��ȡ������ֲ��
bool User::get_vip() {
	return vip;
}

// �����Ƿ�ȫ��ͨ��
void User::set_isAllPassed(bool isAllPassed) {
	this->isAllPassed = isAllPassed;
}

// ��ȡ�Ƿ�ȫ��ͨ��
bool User::get_isAllPassed() {
	return isAllPassed;
}

// ������ʷ��߷�
void User::set_History_Score(long long History_Score) {
	this->History_Score = History_Score;
}

// ��ȡ��ʷ��߷�
long long User::get_History_Score() {
	return History_Score;
}

// �����Ƿ����
void User::set_isInitial(bool isInitial) {
	this->isInitial = isInitial;
}

// ��ȡ�Ƿ����
bool User::get_isInitial() {
	return isInitial;
}

// �����Ƿ��״�ͨ��
void User::set_isFirstPassed(bool isFirstPassed) {
	this->isFirstPassed = isFirstPassed;
}

// �Ƿ��״�ͨ��
bool User::get_isFirstPassed() {
	return isFirstPassed;
}

// ����������Ϣ��˽�У�
void User::setAll(const char PlayerName[22], const char account[22], const char password[22], int Num_Of_isPassed_Level, long long History_Score, bool vip, bool isInitial, bool isAllPassed, bool isFirstPassed) {
	strcpy(this->PlayerName, PlayerName);
	strcpy(this->account, account);
	strcpy(this->password, password);
	this->Num_Of_isPassed_Level = Num_Of_isPassed_Level;
	this->History_Score = History_Score;
	this->vip = vip;
	this->isInitial = isInitial;
	this->isAllPassed = isAllPassed;
	this->isFirstPassed = isFirstPassed;
}

// ��ʾ�û���Ϣ
void User::show() {
	std::cout << "Player Name: " << PlayerName << std::endl;
	std::cout << "Account: " << account << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Number of Passed Levels: " << Num_Of_isPassed_Level << std::endl;
	std::cout << "VIP: " << (vip ? "Yes" : "No") << std::endl;
	std::cout << "All Levels Passed: " << (isAllPassed ? "Yes" : "No") << std::endl;
	std::cout << "History Score: " << History_Score << std::endl;
	std::cout << "Is Initial: " << (isInitial ? "Yes" : "No") << std::endl;
}

// ��¼�ж���1�ɹ�  0δ�ж�  -2�˺Ŵ���  -3�������  -4�ļ���ȡʧ�ܣ�
int User::isLogin(std::string input[]) {
	// �����Ϊ�գ�-1��
	for (int i = 0; i < 2; i++)
		if (input[i].empty())
			return -1;

	int flag{};		// ��1�ɹ�  0δ�ж�  -2�˺Ŵ���  -3�������  -4�ļ���ȡʧ�ܣ�
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// �ļ���ʧ��
	if (!fin.is_open())
		flag = -4;

	// ��ȡ�ļ� -> �ж��˺�����
	while (!fin.read((char*)this, sizeof(User)).eof() && !flag) {
		if (!strcmp(account, input[0].data())) {
			if (!strcmp(password, input[1].data()))
				flag = 1;
			else
				flag = -3;
		}
	}

	// δ�ҵ��˺�
	if (!flag)
		flag = -2;

	// �ر��ļ�
	if (fin.is_open())
		fin.close();

	return flag;
}

// ע���ж���1�ɹ�  0δ�ж�  -1�����Ϊ��  -2�û��Ѵ���  -3���ݻ�ȡʧ��  -4����д��ʧ�ܣ�
int User::Register(std::string input[]) {
	// �����Ϊ�գ�-1��
	for (int i = 0; i < 3; i++)
		if (input[i].empty())
			return -1;

	int flag{};		// ��1�ɹ�  0δ�ж�  -2�û��Ѵ���  -3���ݻ�ȡʧ��  -4����д��ʧ�ܣ�
	std::ofstream fout("./src/data/user.dat", std::ios::binary | std::ios::app);
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// �ļ���ʧ��
	if (!fin.is_open())
		flag = -3;
	if (!fout.is_open())
		flag = -4;

	// ��ȡ�ļ� -> �ж��û��Ƿ����
	while (!fin.read((char*)this, sizeof(User)).eof() && !flag) {
		if (!strcmp(PlayerName, input[0].data()) ||
			!strcmp(account, input[1].data()))
			flag = -2;
	}

	// δ�ҵ��û���д������
	if (!flag) {
		for (int i = 0; i < 3; i++) {
			if (i == 0)	strcpy(PlayerName, input[i].data());
			if (i == 1)	strcpy(account, input[i].data());
			if (i == 2)	strcpy(password, input[i].data());
		}

		setAll(PlayerName, account, password, 0, 0, false, true, false, true);		// ���û�_��ʼ������
		fout.write((char*)this, sizeof(User));
		flag = 1;
	}

	// �ر��ļ�
	if (fin.is_open())
		fin.close();
	if (fout.is_open())
		fout.close();

	return flag;
}

// �����û���Ϣ
bool User::save() {
	User tmp;
	int flag{};		//��1�ɹ�  0δ�ҵ��û�  -1ʧ�ܣ�
	std::ofstream fout("./src/data/tmp.dat", std::ios::binary | std::ios::out);
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// �ļ���ʧ��
	if (!fin.is_open() && !fout.is_open())
		flag = -1;

	// ��ȡ�ļ� -> д������
	while (!fin.read((char*)&tmp, sizeof(User)).eof() && flag != -1) {
		if (!strcmp(PlayerName, tmp.PlayerName) &&
			!strcmp(account, tmp.account)) {
			fout.write((char*)this, sizeof(User));
			flag = 1;
		}
		else
			fout.write((char*)&tmp, sizeof(User));
	}

	// δ�ҵ��û�
	if (flag == 0)
		flag = -1;

	// �ر��ļ�
	if (fin.is_open())
		fin.close();
	if (fout.is_open())
		fout.close();

	// tem.dat -> user.dat
	if (flag == 1) {
		remove("./src/data/user.dat");
		rename("./src/data/tmp.dat", "./src/data/user.dat");
	}

	if (flag == 1)
		return true;
	else
		return false;
}