#!/usr/bin/env ruby



def test_even
    for i in yield
        if i % 2 == 0 
            puts i
        end
    end
end

test_even{[1,2,3,4,5,6]}