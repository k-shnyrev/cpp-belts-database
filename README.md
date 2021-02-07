# Database
Final project from Coursera Modern C++ Development track

## White Belt:
  Программа реализует работу с простой базой данных. Программа общается с пользователем через стандартный ввод и вывод (потоки stdin и stdout).

  В БД хранятся пары вида: дата, событие. Дату - строка вида Год-Месяц-День, где Год, Месяц и День — целые числа. 

  Событие определим как строку из произвольных печатных символов без разделителей внутри (пробелов, табуляций и пр.). Событие не может быть пустой строкой. В одну и ту же дату может произойти много разных событий, БД может их все сохранить. Одинаковые события, произошедшие в один и тот же день, не сохраняются: сохраняется только одно из них.

  ### Возможные команды
  - добавление события: Add Дата Событие
  - удаление события: Del Дата Событие
  - удаление всех событий за конкретную дату: Del Дата
  - поиск событий за конкретную дату: Find Дата
  - печать всех событий за все даты: Print 

  Все команды, даты и события при вводе разделены пробелами. Команды считываются из стандартного ввода. В одной строке может быть ровно одна команда, но можно ввести несколько команд в несколько строк. На вход также могут поступать пустые строки — их следует игнорировать и продолжать обработку новых команд в последующих строках.

  ### Добавление события (Add Дата Событие)
  При добавлении события БД должна его запомнить и затем показывать его при поиске (командой Find) или печати (командой Print). Если указанное событие для данной даты уже существует, повторное его добавление нужно игнорировать. В случае корректного ввода (см. раздел «Обработка ошибок ввода») программа ничего не должна выводить на экран.

  ### Удаление события (Del Дата Событие)
  Команда должна удалить добавленное ранее событие с указанным именем в указанную дату, если оно существует. Если событие найдено и удалено, программа должна вывести строку «Deleted successfully» (без кавычек). Если событие в указанную дату не найдено, программа должна вывести строку «Event not found» (без кавычек).

  ### Удаление нескольких событий (Del Дата)
  Команда удаляет все ранее добавленные события за указанную дату. Программа всегда должна выводить строку вида «Deleted N events», где N — это количество всех найденных и удалённых событий. N может быть равно нулю, если в указанную дату не было ни одного события.

  ### Поиск событий (Find Дата)
  Найти и распечатать ранее добавленные события в указанную дату. Программа должна вывести на печать только сами события, по одному на строке. События должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип string).

  ### Печать всех событий (Print)
  С помощью этой команды можно показать полное содержимое нашей БД. Программа должна вывести на печать все пары Дата Событие по одной на строке. Все пары должны быть отсортированы по дате, а события в рамках одной даты должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип string). Даты должны быть отформатированы специальным образом: ГГГГ-ММ-ДД, где Г, М, Д — это цифры чисел года, месяца и дня соответственно. Если какое-то число имеет меньше разрядов, то оно должно дополняться нулями, например, 0001-01-01 — первое января первого года. Вам не понадобится выводить дату с отрицательным значением года.

  ### Обработка ошибок ввода
  Если пользователь ввёл неизвестную команду, то программа об этом сообщает, выведя строку «Unknown command: COMMAND», где COMMAND — это та команда, которую ввёл пользователь. Командой считается первое слово в строке (до пробела).

  Если дата не соответствует формату Год-Месяц-День, где Год, Месяц и День — произвольные целые числа, то программа выводит «Wrong date format: DATE», где DATE — это то, что пользователь ввёл вместо даты (до пробела). Части даты не могут быть пустыми, но могут быть нулевыми и даже отрицательными.

  Если номер месяца не является числом от 1 до 12, выводится «Month value is invalid: MONTH», где MONTH — это неверный номер месяца, например, 13 или -1.
  Если месяц корректен, а день не лежит в диапазоне от 1 до 31, выводится «Day value is invalid: DAY», где DAY — это неверный номер дня в месяце, например, 39 или 0.
  Календарную корректность даты не проверяется: количество дней в каждом месяце считается равным 31, високосные года не учитываются.
  Если неверны как месяц, так и день, то выводится одно сообщение об ошибке в месяце.

  Примеры:
  1-1-1 — корректная дата;
  -1-1-1 — корректная дата (год -1, месяц 1, день 1);
  1--1-1 — дата в верном формате, но с некорректным месяцем -1;
  1---1-1 — дата в неверном формате: месяц не может начинаться с двух дефисов.
  1-+1-+1 — корректная дата, так как +1 это целое число

  После обработки любой из описанных ошибок ввода и печати сообщения программа завершает своё выполнение.

  ### Предположения
  Каждая команда занимает целиком ровно одну строку, хотя во вводе могут быть и пустые строки (их нужно игнорировать).
  События всегда содержат указанное количество аргументов: после команды Add всегда следуют дата и событие, после команды Find всегда следует дата, после команды Del всегда следует дата и, возможно, событие, а команда Print не содержит дополнительной информации.
  Все команды, даты и события являются непустыми строками и не содержат пробелов и прочих пробельных символов. Команда Del может не содержать события после даты: в этом случае удаляются все события за указанную дату (см. раздел «Удаление нескольких событий»).
