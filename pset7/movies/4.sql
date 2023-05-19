select count(1) from ratings a
inner join movies b on b.id = a.movie_id
where a.rating = 10;