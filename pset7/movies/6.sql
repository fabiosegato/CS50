select avg(b.rating) as avg_rating from movies a
inner join ratings b on b.movie_id = a.id
where a.year = 2012;