# Script for generating the swizzle attributes for each base class
#   so I don't have to type them by hand :)
import itertools
import argparse

MAX_VECN = 4
letter_mapping = {0: ["x", "r"], 1: ["y", "g"], 2: ["z", "b"], 3:["w", "a"]}

# Turn a list of indices into letter mappings
def get_index_letter(indices):
    choices = [[] for _ in range(len(letter_mapping[0]))]
    for index in indices:
        for idx in range(len(choices)):
            choices[idx].append(letter_mapping[index][idx])
    return ', '.join([''.join(choice) for choice in choices])
        
def get_attr_template(args):
    n = len(args)
    str_args = list(map(str, args))
    return f"vec{n}swizzle<vec{n}base<T>, T, {', '.join(str_args)}, 8>  {get_index_letter(args)};"

def get_vector_attributes(n):
    for inner_vec_idx in range(1, MAX_VECN+1):
        for elem in itertools.product(list(range(n)), repeat=inner_vec_idx):
            print(get_attr_template(elem))
        

if __name__=="__main__":
    parser = argparse.ArgumentParser(
                    prog='Swizzle attribute generator',
                    description='This script generates the swizzle attributes for the vector files so you dont have to write them by hand')
    parser.add_argument('n', type=int, help="The dimensionality of the vector you want to generate swizzles for")
    parser.add_argument('-m', '--max-n', type=int, help="The maximum vector value in the current system (note you need to add letters to letter_mapping dictionary in the source file if this is set to > 4)")
    args = parser.parse_args()
    if args.max_n is not None:
        MAX_VECN = args.max_n
    get_vector_attributes(args.n)