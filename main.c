#include "ft_printf.h"

int		main(void)
{
	char str[] = "text123";

	int j = 12;
//	intmax_t j = 9223372036854775807;
	int 	*a;
	int 	i = 1;

	a = &i;


//	ft_printf("(my)--> %i", j);
//	ft_printf("(my)--> %d", j);
//	ft_printf("(my)-->D %D", j);
//	ft_printf("(my)--> %c", 'a');
//	ft_printf("(my)--> %i%c%-10d%i%s", j, 's', 1, 2, "a");
//	ft_printf("(my)--> %s", "text");
//	ft_printf("(my)--> (16-X)->%X", 151231241);
//	printf("(org)--> (16-X)->%X\n", 151231241);
//	ft_printf("(my)--> (10-u)->%hu", 1512321312);
//	ft_printf("(my)--> (10-U)->%hU", 1512321312);
//	printf("(org)--> (10-u)->%hu\n", 1512321312);
//	printf("(org)--> (10-U)->%u\n", 1512321312);
//	ft_printf("(my)--> (8-o)->%o", -1512321312);
//	ft_printf("(my)--> (8-O)->%O", -1512321312);
//	printf("(org)--> (8-o)->%o\n", -1512321312);
//	printf("(org)--> (8-O)->%o\n", -1512321312);
//	ft_printf("(my)-->x (16)->%x", j);
//	printf("(org)-->x (16)-> %x", j);
//	ft_printf("(my)-->p (16)->%p", a);
//	printf("(org)-->p (16)->%p\n", a);

//	ft_printf("(my)-->%d%c%d%i%s", j, 's', 1, 2, "a");
//	printf("(org)-->%text%c%d%i%s", j, 's', 1, 2, "a");
//	ft_printf("(my)-->d % d", j);
//	printf("(org)--> (D)->%# hd\n", j);

//	ft_printf("%s\n", str);
//	printf("%s\n", str);


//	ft_printf("(my)-->[d] %hhd", j);
//	printf("(org)-->[d] %hd", j);


//	printf("1[%-6d]\n", 123);
//	printf("2[%10d]\n", 123);


//	ft_printf("[%-5d]\n", 123);
//	ft_printf("%-5d\n", 567);
//	ft_printf("(may)[%-15d]\n", 567);




//появилась сега !
//		ft_printf("(my)-->%i%c%-30d%i%s", j, 's', 1, 2, "a");

//	printf("(org)[%04d]\n", 123);
//	printf("(org)[%-6d text]\n", 123);
//	ft_printf("(my)[%--6d text]", 123);

//	printf("(org)[%03d]\n", 567);
//	printf("(org)[%09d]\n", 567);
//	ft_printf("(my)[%09d]\n", 567);
//	printf("(org)[%010d]", 123456789);
//	ft_printf("(my)[%010d]", 123456789);




//	ft_printf("(my)[%-15d]", 111);
//	printf("(org)[%-15d]", 111);


	// выводит странно пробелы ...после %  выводит только один (пробел)!
// 	printf("(org)[     %      d     ]", 111);

// не выводит несколько спецыфикаторов сразу !
//	ft_printf("(myy)%d%i%D", -111, 333, 222);

//учитываеться то что ближе к спецификатору
//	ft_printf("(myy)[%123+10d]", -111);

//	printf("(org)[%     4d]", 111);



//	ft_printf("(myy1)[%+010d]", 111);
//	printf("(org1)[%+010d]\n\n", 111);


//	printf("(org2)[%+10d]\n", 111);


//	printf("(org2)[%123+10d]\n", 111);
	// не работает правильно !!!
//	ft_printf("(myy2)[%123+10d]", 111);




//	printf("(org)[   1%      +d   1]", 111);
	// не правильно выводит значение если есть несколько флагов...вывод долежн быть один
	// после обработки уже всех флагоф
//	ft_printf("(myy)[   1%     +d   1]", 111);



//	printf("(org)[%4.d]\n", 111);
//	printf("(org)[%5.d]\n", 111);
//	printf("(org)[%8.7d]\n", 111);
//	printf("(org)[%8.8d]\n", 111);
//	printf("(org)[%16.15d]\n", 111);


// не раблтает
//	ft_printf("(org2)[%+6   d]", 111);
//	printf("(org2)[%+6   d]", 111);
// не раблтает
//	ft_printf("(org2)[%6   d]", 111);
//	printf("(org2)[%6   d]", 111);



//	ft_printf("(myy)[%#7d]", 111);

	// почему то не работает 4 значения вместе ...
//	printf("(org[x])[%#x]\n", 111);
//	ft_printf("(myy[x])[%#x]", 111);
//	printf("(org[X])[%#X]\n", 111);
//	ft_printf("(myy[X])[%#X]", 111);



// не работает !
//	ft_printf("(myy[d])[%+.+10d]", 111);
//	ft_printf("(myy[d])[%+.-10d]", 111);
//	ft_printf("(myy[d])[%-.+10d]", 111);
//	ft_printf("(myy[d])[%-.-10d]", 111);
//------------------




//	ft_printf("(myy[d])[%+10.6d]", 111);
//	printf("(org[d])[%+10.6d]\n", 111);
//
//	ft_printf("(myy[d])[%10.6d]", 111);
//	printf("(org[d])[%10.6d]\n", 111);

//	ft_printf("(myy[d])[%+15.6d]", 111);
//	printf("(org[d])[%+15.6d]\n", 111);

//	ft_printf("(myy[d])[%.6d]", 111);
//	printf("(org[d])[%.6d]\n", 111);
//
//	ft_printf("(myy[d])[%6d]", 111);
//	printf("(org[d])[%6d]\n", 111);
//
//	ft_printf("(myy[d])[%-10.6d]", 111);
//	printf("(org[d])[%-10.6d]\n", 111);
//
//	printf("(org)[%+10d]\n", 111);
//	ft_printf("(myy)[%+10d]", 111);

//	ft_printf("(myy[d])[%+10.6d]", 111);
//	printf("(org[d])[%+10.6d]\n", 111);

//	printf("(org)[%-10d]", 111);
//	ft_printf("(myy)[%-10d]", 111);

//	printf("(org)[%-10d]", 111);
//	ft_printf("(myy)[%-10d]", 111);

	//отменяет все до +10
//	printf("(org)[%.15.1515.15.+10d]", 111);


//----------------
//	printf("(org)[%15.+10d]\n", 111);
//	ft_printf("(myy)[%15.+10d]\n", 111);
//
//	ft_printf("(myy[d])[%+15.+6d]", 111);
//	ft_printf("(myy[d])[%+15.+6d]", 111);


//	ft_printf("(myy[d])[%-15.+6d]\n", 111);
//	printf("(org[d])[%-15.+6d]\n", 111);


	// используеться аргумент ближний к d
//	printf("(org[d])[%-+50.6d]\n", 111);

//	printf("(org[d])[%15.+6d]\n", 111);
//	ft_printf("(myy[d])[%15.+6d]\n", 111);

//	printf("(org[d])[%-6d]\n", 111);

	//----------------------


	ft_printf("(myy[d])[%d%s]", 111);
	printf("(org[d])[%d]\n\n", 111);


//	ft_printf("(myy[d])[%-.10d]", 111);
//	printf("(org[d])[%-.10d]\n\n", 111);

//	ft_printf("(myy[d])[%+-.10d]", 111);
//	printf("(org[d])[%+-.10d]\n", 111);



	//-------------------------
//	ft_printf("(myy[d])[%-7d]", 111);
//	printf("(org[d])[%-7d]\n", 111);

	//-------------------------

//	ft_printf("(myy[d])[%20.15+d]", 111);
//	printf("(org[d])[%20.15+d]\n", 111);

//	ft_printf("(myy[d])[%-+15.6d]", 111);
//	printf("(org[d])[%-+15.6d]\n", 111);


//	ft_printf("(myy[d])[%-+015.6d]", 111);
//	printf("(org[d])[%-+015.6d]\n", 111);

//	printf("(org)[%  +  d]\n", -111);
//	ft_printf("(myy)[%  +  d]\n", -111);


	return (0);
}
