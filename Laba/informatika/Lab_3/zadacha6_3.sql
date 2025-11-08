-- Сначала удаляем все продажи этого продукта
DELETE FROM sales WHERE product_id = 1;

-- Затем удаляем сам продукт
DELETE FROM products WHERE id = 1;

COMMIT;

-- Проверка
SELECT * FROM products WHERE id = 1;
SELECT * FROM sales WHERE product_id = 1;