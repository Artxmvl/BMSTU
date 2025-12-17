--ВЫВОД ВСЕХ ПРОДУКТОВ
SELECT * 
FROM products;

--ВЫВОД ПРОДУКТОВ, ГДЕ quantity < 50
SELECT * 
FROM products
WHERE quantity < 50;

--ВЫВОД ОБЩЕЙ СУММЫ ЗА ОПРЕДЕЛЕННЫЙ ПЕРИОД
SELECT SUM(quantity_sold * price) as total_sales_amount
FROM sales
JOIN products ON sales.product_id = products.id
WHERE sale_date BETWEEN '2025-01-15' AND '2025-01-17';

--Обновления количества продукта на складе после продажи
UPDATE products 
SET quantity = quantity - (
    SELECT COALESCE(SUM(quantity_sold), 0)
    FROM sales 
    WHERE product_id = products.id
);
