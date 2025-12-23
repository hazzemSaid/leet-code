SELECT 
    ROUND(
        100.0 * SUM(CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END) 
        / COUNT(*), 2
    ) AS immediate_percentage
FROM Delivery d
WHERE d.order_date = (
    SELECT MIN(c.order_date)
    FROM Delivery c
    WHERE c.customer_id = d.customer_id
);
