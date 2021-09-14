# task-01
Рынок На рынок пришли N продавцов арбузов и M покупателей. У каждого продавца ровно один
арбуз, и каждый покупатель хочет купить ровно один арбуз. Каждый продавец объявил
минимальную цену, по которой он согласен продать свой арбуз, а каждый покупатель назвал
максимальную цену, по которой он согласен купить арбуз. Конечно, покупатель с радостью
купит арбуз и за более низкую цену, а продавец продаст свой арбуз и дороже, но ни тот, ни
другой не согласны на более плохой для себя вариант. Начались споры. Для назначения
единой цены был вызван директор рынка. В его интересах назначить такую цену, чтобы
суммарная стоимость всех проданных по этой цене арбузов была максимальной. Как это
сделать, не принуждая покупателей и продавцов к изменению заданных ими границ?

Ввод из файла INPUT.TXT. В первой строке содержатся числа N и M (1 ≤ N, M ≤ 100000),
разделенные пробелами. Во второй строке задаются через пробел N чисел: минимальные
допустимые цены продавцов. В третьей строке содержатся M чисел: максимальные цены, за
которые покупатели согласны купить арбуз. Все цены – натуральные числа, не большие
1000000000
Вывод в файл OUTPUT.TXT. Единственная строка должна содержать два числа через
пробел: единую цену, которая принесет максимальную выручку, и размер этой выручки. Если
решений несколько, дать наименьшую единую цену.
Пример
Ввод
3 3
1 3 2
2 2 2
Вывод
2 4
Пояснение. При единой цене 2 свои арбузы готовы продать первый и третий продавцы. За 
эту цену согласны купить арбуз все 3 покупателя. Одному из них арбуза не хватит. Суммарная
выручка составит 4 При единой цене 1 только первый продавец продаст свой арбуз одному из
3 покупателей, готовых его купить, то есть суммарная выручка окажется равной 1 При единой
цене 3 все 3 продавца готовы продать свои арбузы, но ни один из покупателей не согласен
купить такой дорогой арбуз. В этом случае суммарная выручка равна 0