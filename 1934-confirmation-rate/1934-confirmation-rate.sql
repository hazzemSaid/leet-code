SELECT 
    s.user_id,
    round((SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) /
        count(s.user_id) ),2) as confirmation_rate 
FROM Signups s
LEFT JOIN Confirmations c
    ON s.user_id = c.user_id
GROUP BY s.user_id;
