/*
1-There are multiple sales in first year for each product. just return all of them separately.
2-There are some product_id are not in the Product Table, which should be removed from the query
*/
/*
Example Data
product_id	year	   quantity 	price
1       	2019	    10	        100
1	        2019    	5	        120
1	        2020	    8	        110
Expected Output
product_id	first_year	    quantity	price
1	        2019    	    10	        100
1	        2019        	5       	120
*/
select 
    a.product_id,
    year as first_year,
    quantity,
    price
from
     Sales a
JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
    ) f
on
    f.product_id = a.product_id
and
    a.year = f.first_year;