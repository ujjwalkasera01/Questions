# Write your MySQL query statement below
SELECT p.product_id,ROUND(SUM(u.units*p.price)/SUM(u.units),2) AS average_price
FROM prices AS p
JOIN unitssold AS u
ON (p.product_id=u.product_id) AND
(u.purchase_date BETWEEN p.start_date AND p.end_date)
GROUP BY product_id;