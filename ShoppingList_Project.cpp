#include<iostream>
#include<string>
using namespace std;

//Project - Easy Shopping List/
//Name - Leonardo Marcu

class Product
{
private:
	const int id;
	string name;
	double price; //price per 1 quantity
	int quantity; //representing amount of product
	static int increment;

public:
	Product() : id(++increment)
	{
		this->name = "N/A";
		this->price = 0.0;
		this->quantity = 0;
	}

	Product(string name, double price, int quantity) : id(++increment)
	{
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}

	Product(const Product& p) : id(p.id)
	{
		this->name = p.name;
		this->price = p.price;
		this->quantity = p.quantity;
	}

	~Product(){}

	double getPrice()
	{
		return this->price;
	}

	int getQuantity()
	{
		return this->quantity;
	}

	Product& operator=(const Product& p)
	{
		if (this != &p)
		{
			this->name = p.name;
			this->price = p.price;
			this->quantity = p.quantity;
		}

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Product& p)
	{
		out << "Name of product: " << p.name << endl;
		out << "Price: " << p.price << "$" << endl;
		out << "Quantity: " << p.quantity << endl;

		return out;
	}

	friend istream& operator>>(istream& in, Product& p)
	{
		cout << "Insert the name of product: ";
		in.ignore();
		getline(in, p.name);
		cout << "Insert the price: "; in >> p.price;
		cout << "Insert the quantity: "; in >> p.quantity;

		return in;
	}
};
int Product::increment = 0;

class ShoppingList
{
private:

	int numberProducts;
	Product** products; // we have an const in our product class, so we need to do **

public:
	ShoppingList()
	{
		this->numberProducts = 0;
		this->products = nullptr;
	}

	ShoppingList(int numberProducts, Product** products)
	{
		if (numberProducts > 0 && products != nullptr)
		{
			this->numberProducts = numberProducts;
			this->products = new Product * [this->numberProducts];
			for (int i = 0; i < this->numberProducts; i++)
			{
				this->products[i] = new Product(*products[i]);
			}
		}
		else
		{
			this->numberProducts = 0;
			this->products = nullptr;
		}
	}

	~ShoppingList()
	{
		if (this->products != nullptr)
		{
			for (int i = 0; i < this->numberProducts; i++)
			{
				delete this->products[i];
			}

			delete[] this->products;
		}
	}

	int getNumberProducts()
	{
		return this->numberProducts;
	}
	//this is a method where we can add a product in our shopping list, implemented in an operator
	ShoppingList& operator+=(const Product& p)
	{
		ShoppingList copy = *this;
		for (int i = 0; i < this->numberProducts; i++)
		{
			delete this->products[i];
		}

		delete[] this->products;

		this->numberProducts++;
		this->products = new Product * [this->numberProducts];
		for (int i = 0; i < copy.numberProducts; i++)
		{
			this->products[i] = new Product(*copy.products[i]);
		}
		this->products[this->numberProducts - 1] = new Product(p);

		return *this;
	}

	friend ostream& operator<<(ostream& out, const ShoppingList& sl)
	{
		out << "--- Shopping List! ---" << endl;
		out << "Number of products: " << sl.numberProducts << endl;
		out << "Products: " << endl;
		for (int i = 0; i < sl.numberProducts; i++)
		{
			out << *sl.products[i] << endl;
		}

		return out;
	}


	double finalPrice()
	{
		
		double totalPrice = 0.0;
		for (int i = 0; i < this->numberProducts; i++)
		{
			totalPrice += products[i]->getPrice() * products[i]->getQuantity();
		}
		cout << "Final price of this Shopping List: " << totalPrice << "$" << endl;

		return 0.0;
	}

};

int main()
{
	Product product1("Bread", 2, 2);
	cout << "--- Products ---" << endl;
	cout << product1;
	cout << "--------------------" << endl;

	int val;
	cout << "Do you wanna insert a new product? (1-YES,0-N0) :"; cin >> val;
	
	Product product2;
	
	if (val == 1)
	{
		cin >> product2;
		cout << "There it is the new product: " << endl;
		cout << product2;
		cout << "--------------------" << endl;
	}
	

	Product product3("Strawberry 100g", 5, 4);
	Product product4("Cherries 175g", 11, 1);

	Product* products1[] = { &product1,&product2,&product3,&product4 };
	int numberP = 4;

	ShoppingList List1(numberP, products1);
	cout << "--- ShoppingList ---" << endl;
	cout << List1;
	cout << "-----------------------" << endl;
	List1.finalPrice();
}