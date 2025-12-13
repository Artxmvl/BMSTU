-- ===============================
-- INITIAL DATA
-- ===============================

INSERT INTO categories (category_name) VALUES
('Electronics'),
('Clothing'),
('Books'),
('Software')
ON CONFLICT DO NOTHING;

INSERT INTO products (name, price, quantity, category_id) VALUES
('Laptop', 50000, 10, 1),
('Smartphone', 30000, 20, 1),
('T-shirt', 1500, 50, 2),
('Jeans', 3000, 30, 2),
('E-book', 500, 100, 3),
('Video course', 2000, 200, 4)
ON CONFLICT DO NOTHING;

INSERT INTO sales (product_id, sale_date, quantity_sold) VALUES
(1, '2024-01-15', 2),
(2, '2024-01-16', 5),
(3, '2024-01-17', 10),
(4, '2024-01-18', 3),
(5, '2024-01-19', 25),
(6, '2024-01-20', 15)
ON CONFLICT DO NOTHING;

-- ===============================
-- QUERIES (same as in C++)
-- ===============================

-- Show categories
SELECT id, category_name
FROM categories
ORDER BY id;

-- Show products
SELECT p.id, p.name, p.price, p.quantity, c.category_name
FROM products p
JOIN categories c ON p.category_id = c.id
ORDER BY p.id;

-- Show sales
SELECT s.id, p.name, s.sale_date, s.quantity_sold
FROM sales s
JOIN products p ON p.id = s.product_id
ORDER BY s.sale_date;

-- TOP-5 products
SELECT p.name, SUM(s.quantity_sold) AS total_sold
FROM sales s
JOIN products p ON p.id = s.product_id
GROUP BY p.name
ORDER BY total_sold DESC
LIMIT 5;
