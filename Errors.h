class Errors
{
public:
	Errors(int t);///<Конструктор ініціалізації
	~Errors(); ///<Деструктор 
	void Variety();///<Обробка помилки неправльно обраного варіанту з можливих
	void Number();///<Обробка помилик введення не числа

private:
	int typeOfException;///<Тип помилки
}; 
