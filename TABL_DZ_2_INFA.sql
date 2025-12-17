-- ===============================
-- Удаление таблиц
-- ===============================
DROP TABLE IF EXISTS sales_fact CASCADE;
DROP TABLE IF EXISTS time_dim CASCADE;
DROP TABLE IF EXISTS products_dim CASCADE;
DROP TABLE IF EXISTS customers_dim CASCADE;

-- ===============================
-- Таблица товаров
-- ===============================
CREATE TABLE products_dim (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    price NUMERIC(10,2)
);

-- ===============================
-- Таблица клиентов
-- ===============================
CREATE TABLE customers_dim (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(100),
    region VARCHAR(50)
);

-- ===============================
-- Таблица времени
-- ===============================
CREATE TABLE time_dim (
    time_id SERIAL PRIMARY KEY,
    date DATE UNIQUE,
    year INT,
    quarter INT,
    month INT,
    day INT,
    day_of_week VARCHAR(20)
);

-- ===============================
-- Фактическая таблица продаж
-- ===============================
CREATE TABLE sales_fact (
    sale_id INT PRIMARY KEY,
    sale_date DATE,
    product_id INT REFERENCES products_dim(product_id),
    customer_id INT REFERENCES customers_dim(customer_id),
    quantity INT,
    amount NUMERIC(10,2)
);

-- ===============================
-- Заполнение products_dim
-- ===============================
INSERT INTO products_dim VALUES
(1, 'Телефон', 'Электроника', 25000),
(2, 'Ноутбук', 'Электроника', 80000),
(3, 'Стол', 'Мебель', 15000);

-- ===============================
-- Заполнение customers_dim
-- ===============================
INSERT INTO customers_dim VALUES
(1, 'Иван Иванов', 'Москва'),
(2, 'Петр Петров', 'СПб'),
(3, 'Анна Смирнова', 'Казань');

-- ===============================
-- Индексы
-- ===============================
CREATE INDEX IF NOT EXISTS idx_sales_fact_product
ON sales_fact(product_id);

CREATE INDEX IF NOT EXISTS idx_sales_fact_customer
ON sales_fact(customer_id);

CREATE INDEX IF NOT EXISTS idx_sales_fact_date
ON sales_fact(sale_date);

CREATE INDEX IF NOT EXISTS idx_products_dim_category
ON products_dim(category);

CREATE INDEX IF NOT EXISTS idx_customers_dim_region
ON customers_dim(region);

-- ===============================
-- Заполнение time_dim
-- ===============================
INSERT INTO time_dim (date, year, quarter, month, day, day_of_week)
SELECT DISTINCT
    sale_date,
    EXTRACT(YEAR FROM sale_date),
    EXTRACT(QUARTER FROM sale_date),
    EXTRACT(MONTH FROM sale_date),
    EXTRACT(DAY FROM sale_date),
    TO_CHAR(sale_date, 'Day')
FROM sales_fact
ON CONFLICT (date) DO NOTHING;

--для проверки
SELECT * FROM products_dim;
SELECT * FROM customers_dim;
SELECT * FROM sales_fact;
SELECT * FROM time_dim;