#include<iostream>

 //static - относительно элементов класса.

class SequencesGenerator {
public:
	void M00()const{}


	static void M01(){}
	//позволяет создавать вызовы метода без создания объекта класса

	static int NextNum() {
		//static int n{};
		//M00(); нет доступа так как нет указателей на себя
		M01();
		return n++;
	}

	//в статических методах нельзя обращаться к нестатическим элементам класса
private:
	static int n;
	//неконстантные статические поля нельзя использовать без инициализации
	//и их определение должно происходить вне класса

	//константные статические поля допустимо определять в теле класа
};

//Определение статических полей всегда выносим в файлы кода

int SequencesGenerator::n{ 15 };



//такая функция будет запрещена для вызова в других кодовых файлах программы
static int NumSequense() {
	static int n{}; //с помощью static переместили переменную в глобальную память программы

	return n++;
}

// создать класс который без создания объектов мог бы сообщать свое название
//данный класс сделать на примере животного




void CatDemo();

int main() {
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < 5; i++) {
		std::cout << NumSequense() << '\n';

	}


	//SequencesGenerator obj;
	for (int i = 0; i < 5; i++) {
		std::cout << SequencesGenerator::NextNum() << '\n';

	}


	CatDemo();
	return 0;

}

class Cat {
public:
	static void Name() {
		std::cout << name;
	}

	void Say()const {
		Name();
		std::cout << " Мяу\n";
	}

	void Feed(std::string food)const {
		Name();
		std::cout << " eat: " << food << '\n';

	}

private:
	static std::string name;//объявление 
};

	std::string Cat:: name { "Barsik" };// определение и начальное значения

	void CatDemo() {
		std::cout << "We have a Cat ";
		Cat::Name();
		std::cout << '\n';
		Cat cat;
		cat.Feed(" mice");
		cat.Say();
	}





