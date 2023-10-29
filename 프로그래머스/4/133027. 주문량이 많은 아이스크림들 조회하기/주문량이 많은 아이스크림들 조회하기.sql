select FLAVOR from (select t.flavor, sum(t.total_order) as q from (select * from first_half
union
select * from july) as t
group by t.flavor
order by q desc) as t
limit 3