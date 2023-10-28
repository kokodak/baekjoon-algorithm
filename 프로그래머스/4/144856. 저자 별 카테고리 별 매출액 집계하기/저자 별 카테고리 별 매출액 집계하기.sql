-- 코드를 입력하세요
select AUTHOR_ID, AUTHOR_NAME, CATEGORY, TOTAL_SALES from
(SELECT a.author_id, a.author_name, b.category, sum(b.price * bs.sales) as TOTAL_SALES from book as b 
 join author as a on b.author_id = a.author_id 
 join book_sales as bs on b.book_id = bs.book_id 
 where bs.sales_date like '2022-01%'
 group by b.author_id, b.category) as t
order by author_id asc, category desc

# SELECT
# b.AUTHOR_ID,
# a.AUTHOR_NAME,
# b.CATEGORY,
# SUM(bs.SALES * b.PRICE) TOTAL_SALES
# FROM
# BOOK_SALES bs 
# JOIN BOOK b
# ON bs.BOOK_ID = b.BOOK_ID
# JOIN AUTHOR a
# ON b.AUTHOR_ID = a.AUTHOR_ID
# WHERE bs.SALES_DATE BETWEEN "2022-01-01" AND "2022-01-31"
# GROUP BY b.AUTHOR_ID, b.CATEGORY
# ORDER BY b.AUTHOR_ID, b.CATEGORY DESC;