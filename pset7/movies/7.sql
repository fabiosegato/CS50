select a.title,b.rating from movies a
inner join ratings b on b.movie_id = a.id
where a.year = 2010
order by rating desc, title;