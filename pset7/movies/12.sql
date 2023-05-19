select
c.title
from
people a
inner join stars b on b.person_id = a.id
inner join movies c on c.id = b.movie_id
where name = 'Johnny Depp' or name = 'Helena Bonham Carter'
group by b.movie_id
having count(1) > 1;