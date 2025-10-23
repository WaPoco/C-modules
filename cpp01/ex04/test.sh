#!/usr/bin/env bash

EXE=./sed

test0=("hello apple world, apple pie!" "apple" "orange")

test1=("apple is tasty
banana is yellow
apple again" "apple" "APPLE")   

test2=("no apples here
only bananas" "mango" "peach")

test3=("ha ha ha ha" "ha" "he")

test4=("aaaa" "aa" "b")

test5=("foo bar foo baz" "foo" "a")

tests=(test0 test1 test2 test3 test4 test5)

run_test()
{
    local name="$1"
    local input s1 s2
    local infile="${name}"

    eval "input=\${${name}[0]}"
    eval "s1=\${${name}[1]}"
    eval "s2=\${${name}[2]}"

    echo ""
    printf '🧪 Running %s s1=%q s2=%q\n' "$name" "$s1" "$s2"
    printf '%s' "$input" > "$infile"

    "$EXE" "$infile" "$s1" "$s2"
    
    if [ -n "$s1" ]; then
        sed "s/${s1}/${s2}/g" "$infile" > "ref.replace.${infile}"
    fi

    echo "input:"
    cat "$infile"
    echo ""
    echo ""
    echo "output:"
    cat "replace.${infile}"
    echo ""
    echo ""
    echo "sed output:"
    cat "ref.replace.${infile}"
    echo ""
    echo ""

    # Compare
    if diff -u "ref.replace.${infile}" "replace.${infile}" >/dev/null; then
        echo "✅ $name matches system sed"
    else
        echo "❌ $name differs from system sed"
        diff -u "ref.replace.${infile}" "replace.${infile}" || true
    fi
    echo ""
}

# run all tests
for t in "${tests[@]}"; do
  run_test "$t"
done

for ((i=0; i<${#tests[@]}; i++)); do
    rm -f "test${i}"
    rm -f "replace.test${i}"
    rm -f "ref.replace.test${i}"
done
