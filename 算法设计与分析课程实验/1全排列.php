<?php
/* User:itonlin; Date:2018/10/31; */
$input = 'abcd';
//abcd
//abdc
//acbd
//acdb
//adbc
//adcb
//应该是24个
$res = [];
function dump_full_permulate(&$str, $start)
{
    $index = $start;
    $index_two = $start;


    if($index < strlen($str))
    {
        while ($index_two < strlen($str)) {
            //换过去
            $temp = $str[$index_two];
            $str[$index_two] = $str[$index];
            $str[$index] = $temp;

            //输出
            dump_full_permulate($str, $start+1);
            //echo $str."\n";

            //换回来
            $temp = $str[$index_two];
            $str[$index_two] = $str[$index];
            $str[$index] = $temp;
            $index_two++;
        }
    }else{
        //echo $str."\n";
        global $res;
        $res[] = $str;
    }
}

dump_full_permulate($input, 0);
var_dump($res);