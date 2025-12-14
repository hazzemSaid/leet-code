SELECT w.id
FROM Weather w
LEFT JOIN Weather b
  ON DATEDIFF(w.recordDate, b.recordDate) = 1
     AND w.temperature > b.temperature
WHERE b.id IS NOT NULL;
