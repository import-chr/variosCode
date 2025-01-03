def decimal_roman(decimal):
    roman_nums = [(1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
                  (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
                  (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')]
    
    roman = ''

    for val, num in roman_nums:
        while decimal >= val:
            roman += num
            decimal -= val
    
    return roman

dec_number = int(input('Enter a decimal number: '))
roman_number = decimal_roman(dec_number)
print(f'The Roman numeral for {dec_number} is {roman_number}')