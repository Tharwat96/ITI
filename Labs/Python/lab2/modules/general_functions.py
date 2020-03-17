import json


def write_dict_to_json(fname, data):
    with open(f'data/{fname}.json', 'w') as f:
        json.dump(data, f, sort_keys=True, indent=4, default=str)
    f.close()


def print_dict(d):
    for key, value in d.items():
        if isinstance(value, dict):
            print("================")
            print(key)
            print_dict(value)
        else:
            print("{0}: {1}".format(key, value))
