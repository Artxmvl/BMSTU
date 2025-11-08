--удаление таблиц
DROP TABLE IF EXISTS sales;
DROP TABLE IF EXISTS products;
DROP TABLE IF EXISTS categories;
--создание новых таблиц
CREATE TABLE categories(
	id INT PRIMARY KEY,
	category_name varchar(100)
);


CREATE TABLE products(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	price FLOAT,
	quantity INT,
	category_id INT,
	FOREIGN KEY (category_id) REFERENCES categories(id)
);


CREATE TABLE sales(
	id INT PRIMARY KEY,
	product_id INT,
	sale_date DATE,
	quantity_sold INT,
	FOREIGN KEY (product_id) REFERENCES products(id)
);

--заполнение всех таблиц
INSERT INTO categories(id,category_name) VALUES
(1,'Овощи'),
(2,'Фрукты'),
(3,'Молочные продукты'),
(4,'Мясные продукты');

INSERT INTO products(id,name,price,quantity,category_id) VALUES
(1, 'Помидоры', 150.00, 100, 1),
(2, 'Огурцы', 120.00, 80, 1),
(3, 'Яблоки', 89.90, 150, 2),
(4, 'Бананы', 99.50, 120, 2),
(5, 'Молоко', 75.00, 50, 3),
(6, 'Сыр', 450.00, 30, 3),
(7, 'Курица', 350.00, 25, 4),
(8, 'Говядина', 650.00, 15, 4);

INSERT INTO sales (id, product_id, sale_date, quantity_sold) VALUES
(1, 1, '2025-01-15', 5),
(2, 2, '2025-01-15', 3),
(3, 3, '2025-01-16', 10),
(4, 5, '2025-01-16', 8),
(5, 1, '2025-01-17', 7),
(6, 6, '2025-01-17', 2),
(7, 7, '2025-01-18', 1),
(8, 4, '2025-01-18', 15),
(9, 8, '2025-01-19', 3);






