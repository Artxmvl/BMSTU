-- Изменение цены на +10% для овощей
UPDATE products 
SET price = price * 1.10 
WHERE category_id = (SELECT id FROM categories WHERE category_name = 'Овощи');

-- Изменение цены на +15% для фруктов
UPDATE products 
SET price = price * 1.15 
WHERE category_id = (SELECT id FROM categories WHERE category_name = 'Фрукты');

-- Изменение цены на -5% для молочных продуктов
UPDATE products 
SET price = price * 0.95 
WHERE category_id = (SELECT id FROM categories WHERE category_name = 'Молочные продукты');

-- Проверка изменений
SELECT p.name, c.category_name, p.price 
FROM products p 
JOIN categories c ON p.category_id = c.id 
ORDER BY c.category_name, p.name;