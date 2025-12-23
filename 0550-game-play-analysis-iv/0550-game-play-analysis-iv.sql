SELECT 
    ROUND(
        1.0 * SUM(
            CASE 
                WHEN EXISTS (
                    SELECT 1
                    FROM Activity b
                    WHERE b.player_id = a.player_id
                      AND DATEDIFF(b.event_date, a.first_login) = 1
                ) THEN 1 ELSE 0
            END
        ) / COUNT(*), 2
    ) AS fraction 
FROM (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) a;
