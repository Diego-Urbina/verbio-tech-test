# verbio-tech-test

## Build
mkdir release \
cd release \
cmake -DCMAKE_BUILD_TYPE=Release .. \
cmake --build . \

## Usage
### Interactive mode
*./VerbioTechnicalTest* allows you write sentences until you exit with ":q"

### File mode
*./VerbioTechnicalTest -f filename* reads a file and translate all the sentences

### Test mode
*./VerbioTechnicalTest -t* launches some tests

## Algorithm
### Definitions
*Number*: units or tens \
*Magnitude*: hundred, thousan, million or billion
```
total = 0
current = 0
end = false
error = false
while (not end)
{
  word = readWord();
  if (word is Number)
  {
    if (magnitude(word) < magnitude(current)
    {
      current = current + word
    }
    else
    {
      end = true
      error = true
    }
  }
  else if (word is Magnitude)
  {
    if (current == 0 or magnitude(current) >= magnitude(word))
    {
      end = true
      error = true
    }
    
    current = current * word
    
    if (word >= 1000)
    {
      if (total != 0 and magnitude(total) <= magnitude(current))
      {
        end = true
        error = true
      }
      
      total = current
      current = 0
    }
  }
  else
    end = true
}
```

## Evolution
I use an IParser interface. So it's possible to achieve other translations just using a new Parser, for example, an EmojiParser!

## Potential fixes and improvements
I know there is a problem with the tokenizer method. I use whitespaces for spliting the string, and that's the reason because it doesn't split properly a word follows by other character. It doesn't detect "Five?" for example. I tried to use regex but I don't have enought time and I consider that is not the main purpose of the test
