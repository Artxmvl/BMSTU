SELECT 
    products.name as product_name, --название товара
    categories.category_name, --категория товара
    SUM(sales.quantity_sold) as total_sold --нахождение суммы
FROM sales
JOIN products ON sales.product_id = products.id
JOIN categories ON products.category_id = categories.id
GROUP BY products.id, products.name, categories.category_name группипруем товары
ORDER BY total_sold DESC --сортируем от большего к меньшему
LIMIT 3;