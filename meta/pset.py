import urllib.request
import re

def fetch():
    url = 'https://cses.fi/problemset/'

    print(f'Fetching {url} ...')
    page = urllib.request.urlopen('https://cses.fi/problemset/').read().decode()

    print(f'Parsing problem set ...')
    pattern = r'<h2>(.*?)</h2>|<a href="(/problemset/.*?)">(.*?)</a>'
    section = ''
    problems = {}
    for headig, href, anchor in re.findall(pattern, page):
        if headig != '':
            section = headig
            continue

        if section == 'General':
            continue

        if section not in problems:
            problems[section] = []
        problems[section].append((f'http://cses.fi{href}', anchor))
    return problems


def mdtable(problems):
    result = ''
    total = sum(len(items) for _, items in problems.items())
    i = 0
    result += '| # | Section Title | Section # | Problem Title and Link |\n'
    result += '| :- | :- | :- | :- |\n'
    for section, items in problems.items():
        for j, (url, title) in enumerate(items, 1):
            i += 1
            result += f'| {i:03} of {total} | {section} | {j:02} of {len(items):02} | [{title}]({url})\n'
    return result


def header():
    return """# CSES Problem Set

This document contains a numbered list of all the problems from the
[CSES Problem Set](https://cses.fi/problemset/).  Two ordinal numbers
are mentioned against each problem.  The first number shows the
position of the problem in the entire problem set.  The second number
shows the position of the problem within a section.  This numbering
holds good for the CSES May 2025 Update which consisted a total of 400
problems.

"""

def main():
    problems = fetch()
    text = header()
    text += mdtable(problems)
    with open('pset.md', 'w') as f:
        f.write(text)

if __name__ == '__main__':
    main()
