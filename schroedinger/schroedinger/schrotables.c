
#include <schroedinger/schrotables.h>

int16_t schro_table_offset[61] = {
      0,     0,     0,     1,
      1,     1,     1,     1,
      2,     2,     2,     3,
      3,     4,     4,     5,
      6,     7,     9,    10,
     12,    14,    17,    20,
     24,    29,    34,    41,
     48,    57,    68,    81,
     96,   114,   136,   162,
    192,   228,   272,   323,
    384,   457,   543,   646,
    768,   913,  1086,  1292,
   1536,  1827,  2172,  2583,
   3072,  3653,  4344,  5166,
   6144,  7307,  8689, 10333,
  12288
};

int16_t schro_table_quant[61] = {
      1,     1,     1,     2,
      2,     2,     3,     3,
      4,     5,     6,     7,
      8,    10,    11,    13,
     16,    19,    23,    27,
     32,    38,    45,    54,
     64,    76,    91,   108,
    128,   152,   181,   215,
    256,   304,   362,   431,
    512,   609,   724,   861,
   1024,  1218,  1448,  1722,
   2048,  2435,  2896,  3444,
   4096,  4871,  5793,  6889,
   8192,  9742, 11585, 13777,
  16384, 19484, 23170, 27554,
  32768
};

uint32_t schro_table_division_factor[256] = {
  2147483648u, 1073741824u,  715827882u,  536870912u,
   429496729u,  357913941u,  306783378u,  268435456u,
   238609294u,  214748364u,  195225786u,  178956970u,
   165191049u,  153391689u,  143165576u,  134217728u,
   126322567u,  119304647u,  113025455u,  107374182u,
   102261126u,   97612893u,   93368854u,   89478485u,
    85899345u,   82595524u,   79536431u,   76695844u,
    74051160u,   71582788u,   69273666u,   67108864u,
    65075262u,   63161283u,   61356675u,   59652323u,
    58040098u,   56512727u,   55063683u,   53687091u,
    52377649u,   51130563u,   49941480u,   48806446u,
    47721858u,   46684427u,   45691141u,   44739242u,
    43826196u,   42949672u,   42107522u,   41297762u,
    40518559u,   39768215u,   39045157u,   38347922u,
    37675151u,   37025580u,   36398027u,   35791394u,
    35204649u,   34636833u,   34087042u,   33554432u,
    33038209u,   32537631u,   32051994u,   31580641u,
    31122951u,   30678337u,   30246248u,   29826161u,
    29417584u,   29020049u,   28633115u,   28256363u,
    27889398u,   27531841u,   27183337u,   26843545u,
    26512143u,   26188824u,   25873296u,   25565281u,
    25264513u,   24970740u,   24683720u,   24403223u,
    24129029u,   23860929u,   23598721u,   23342213u,
    23091222u,   22845570u,   22605091u,   22369621u,
    22139006u,   21913098u,   21691754u,   21474836u,
    21262214u,   21053761u,   20849355u,   20648881u,
    20452225u,   20259279u,   20069940u,   19884107u,
    19701684u,   19522578u,   19346699u,   19173961u,
    19004280u,   18837575u,   18673770u,   18512790u,
    18354561u,   18199013u,   18046081u,   17895697u,
    17747798u,   17602324u,   17459216u,   17318416u,
    17179869u,   17043521u,   16909320u,   16777216u,
    16647160u,   16519104u,   16393004u,   16268815u,
    16146493u,   16025997u,   15907286u,   15790320u,
    15675063u,   15561475u,   15449522u,   15339168u,
    15230380u,   15123124u,   15017368u,   14913080u,
    14810232u,   14708792u,   14608732u,   14510024u,
    14412641u,   14316557u,   14221746u,   14128181u,
    14035840u,   13944699u,   13854733u,   13765920u,
    13678239u,   13591668u,   13506186u,   13421772u,
    13338407u,   13256071u,   13174746u,   13094412u,
    13015052u,   12936648u,   12859183u,   12782640u,
    12707003u,   12632256u,   12558383u,   12485370u,
    12413200u,   12341860u,   12271335u,   12201611u,
    12132675u,   12064514u,   11997115u,   11930464u,
    11864550u,   11799360u,   11734883u,   11671106u,
    11608019u,   11545611u,   11483869u,   11422785u,
    11362347u,   11302545u,   11243369u,   11184810u,
    11126858u,   11069503u,   11012736u,   10956549u,
    10900932u,   10845877u,   10791375u,   10737418u,
    10683998u,   10631107u,   10578737u,   10526880u,
    10475529u,   10424677u,   10374317u,   10324440u,
    10275041u,   10226112u,   10177647u,   10129639u,
    10082082u,   10034970u,    9988296u,    9942053u,
     9896238u,    9850842u,    9805861u,    9761289u,
     9717120u,    9673349u,    9629971u,    9586980u,
     9544371u,    9502140u,    9460280u,    9418787u,
     9377657u,    9336885u,    9296466u,    9256395u,
     9216668u,    9177280u,    9138228u,    9099506u,
     9061112u,    9023040u,    8985287u,    8947848u,
     8910720u,    8873899u,    8837381u,    8801162u,
     8765239u,    8729608u,    8694265u,    8659208u,
     8624432u,    8589934u,    8555711u,    8521760u,
     8488077u,    8454660u,    8421504u,    8388608u
};
