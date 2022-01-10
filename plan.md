# English Word Tester in Command line

## Objective

- See a english word and Write a right mean.
  - 한 영어단어에 여러 의미가 있을 경우, 한 가지 의미만 적어도 정답 처리
- See a mean and Write a English word
  - 여러 의미가 있을 경우 여러 의미를 모두 보여준다.

- If tester have wrong answer, show the word what tester wrong

## Data Format

```json
<english word> : [
    <korean mean>, <korean mean>, ...
]
```

## CMD GUI Format

### Testing GUI

```
<Total Score>/<Correct Score>
<English Word>
>>_
```

### Score GUI

```
<Total Score>/<Correct Score>

### Wrong Word ###
<English Word> | <Korean mean>, <Korean mean>, ...
<English Word> | <Korean mean>, <Korean mean>, ...
<English Word> | <Korean mean>, <Korean mean>, ...
...

Total 3 Wrong Word
```
