Spécificateur	Signification		Type de base		Modificateurs valides
--------------------------------------------------------------------------------
d, i			Entier signé		int					hh, h, l, ll, j, z, t
u, x, X			Entier non signé	unsigned int		hh, h, l, ll, j, z, t
c				Caractère			int ou wint_t		l (pour wchar_t)
s				Chaîne				char* ou wchar_t*	l (pour wide string)
p				Pointeur			void*				(pas de length mod)
%				Littéral %			—					(aucun)
