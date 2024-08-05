#include "User.h"


// 构造函数
User::User()
	: PlayerName(), account(), password(),
	Num_Of_isPassed_Level(), History_Score(),
	vip(false),
	isInitial(true),
	isAllPassed(false),
	isFirstPassed(true)
{}

// 获取玩家名称
const std::string User::get_PlayerName() {
	return std::string(PlayerName);
}

// 获取账号
const std::string User::get_account() {
	return std::string(account);
}

// 设置通过的关卡数
void User::set_Num_Of_isPassed_Level(int Num_Of_isPassed_Level) {
	this->Num_Of_isPassed_Level = Num_Of_isPassed_Level;
}

// 获取通过的关卡数
int User::get_Num_Of_isPassed_Level() {
	return Num_Of_isPassed_Level;
}

// 设置解锁的植物
void User::set_vip(bool vip) {
	this->vip = vip;
}

// 获取解锁的植物
bool User::get_vip() {
	return vip;
}

// 设置是否全部通过
void User::set_isAllPassed(bool isAllPassed) {
	this->isAllPassed = isAllPassed;
}

// 获取是否全部通过
bool User::get_isAllPassed() {
	return isAllPassed;
}

// 设置历史最高分
void User::set_History_Score(long long History_Score) {
	this->History_Score = History_Score;
}

// 获取历史最高分
long long User::get_History_Score() {
	return History_Score;
}

// 设置是否初次
void User::set_isInitial(bool isInitial) {
	this->isInitial = isInitial;
}

// 获取是否初次
bool User::get_isInitial() {
	return isInitial;
}

// 设置是否首次通关
void User::set_isFirstPassed(bool isFirstPassed) {
	this->isFirstPassed = isFirstPassed;
}

// 是否首次通关
bool User::get_isFirstPassed() {
	return isFirstPassed;
}

// 设置所有信息（私有）
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

// 显示用户信息
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

// 登录判定（1成功  0未判定  -2账号错误  -3密码错误  -4文件读取失败）
int User::isLogin(std::string input[]) {
	// 输入框为空（-1）
	for (int i = 0; i < 2; i++)
		if (input[i].empty())
			return -1;

	int flag{};		// （1成功  0未判定  -2账号错误  -3密码错误  -4文件读取失败）
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// 文件打开失败
	if (!fin.is_open())
		flag = -4;

	// 读取文件 -> 判定账号密码
	while (!fin.read((char*)this, sizeof(User)).eof() && !flag) {
		if (!strcmp(account, input[0].data())) {
			if (!strcmp(password, input[1].data()))
				flag = 1;
			else
				flag = -3;
		}
	}

	// 未找到账号
	if (!flag)
		flag = -2;

	// 关闭文件
	if (fin.is_open())
		fin.close();

	return flag;
}

// 注册判定（1成功  0未判定  -1输入框为空  -2用户已存在  -3数据获取失败  -4数据写入失败）
int User::Register(std::string input[]) {
	// 输入框为空（-1）
	for (int i = 0; i < 3; i++)
		if (input[i].empty())
			return -1;

	int flag{};		// （1成功  0未判定  -2用户已存在  -3数据获取失败  -4数据写入失败）
	std::ofstream fout("./src/data/user.dat", std::ios::binary | std::ios::app);
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// 文件打开失败
	if (!fin.is_open())
		flag = -3;
	if (!fout.is_open())
		flag = -4;

	// 读取文件 -> 判定用户是否存在
	while (!fin.read((char*)this, sizeof(User)).eof() && !flag) {
		if (!strcmp(PlayerName, input[0].data()) ||
			!strcmp(account, input[1].data()))
			flag = -2;
	}

	// 未找到用户，写入数据
	if (!flag) {
		for (int i = 0; i < 3; i++) {
			if (i == 0)	strcpy(PlayerName, input[i].data());
			if (i == 1)	strcpy(account, input[i].data());
			if (i == 2)	strcpy(password, input[i].data());
		}

		setAll(PlayerName, account, password, 0, 0, false, true, false, true);		// 新用户_初始化数据
		fout.write((char*)this, sizeof(User));
		flag = 1;
	}

	// 关闭文件
	if (fin.is_open())
		fin.close();
	if (fout.is_open())
		fout.close();

	return flag;
}

// 保存用户信息
bool User::save() {
	User tmp;
	int flag{};		//（1成功  0未找到用户  -1失败）
	std::ofstream fout("./src/data/tmp.dat", std::ios::binary | std::ios::out);
	std::ifstream fin("./src/data/user.dat", std::ios::binary | std::ios::in);

	// 文件打开失败
	if (!fin.is_open() && !fout.is_open())
		flag = -1;

	// 读取文件 -> 写入数据
	while (!fin.read((char*)&tmp, sizeof(User)).eof() && flag != -1) {
		if (!strcmp(PlayerName, tmp.PlayerName) &&
			!strcmp(account, tmp.account)) {
			fout.write((char*)this, sizeof(User));
			flag = 1;
		}
		else
			fout.write((char*)&tmp, sizeof(User));
	}

	// 未找到用户
	if (flag == 0)
		flag = -1;

	// 关闭文件
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