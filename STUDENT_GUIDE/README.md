# C Programming Course — Student-contributed study guide

**LINK FROM THE OFFICIAL REPO (running the MKDOCS):**\
https://1kumo.github.io/C-Learning/

<br>

A structured, bilingual study guide for learning the C programming language. The site brings together a core course, a set of advanced topics, and exercise sheets in both French and English.

## About

This repository contains the source of a MkDocs Material website. The student-contributed revision guide uses **Tatiana Aubonnet's** C course (2008) as a topic reference and draws primarily on exercises shared by **[S-L-A-K-E-R](https://github.com/S-L-A-K-E-R)**.

The material covers the fundamentals of C (variables, control flow, arrays, functions, pointers, strings, dynamic memory, structures, files, sorting, searching, and linked lists), followed by a "beyond the core" section on complexity, recursion, sorting, advanced search, memory reliability, strings and parsing, and file handling.

## Goals and audience

- Provide clear revision material for students following a first C programming course.
- Offer a self-paced reference with short, topic-focused chapters.
- Give learners immediate practice material through six exercise sheets per language.
- Keep French and English versions aligned so that either audience can follow the same path.

The intended audience is beginners and intermediate learners, as well as teachers looking for a ready-to-use structure and exercise set.

## Features

- **Bilingual content**: complete French and English sections with the same organization.
- **Two learning levels**: a core course and a complementary "beyond the core" section.
- **Exercise sheets**: six sheets per language, available as Markdown exercise statements and as the original PDFs.
- **Contextual practice links**: relevant course sections link directly to the matching exercise sheet.
- **Readable on any screen**: dark/light theme switch, sectioned navigation, search, and copyable code blocks.
- **Static output**: the generated site can be hosted on any static file host.

## Language support and navigation

| Language | Overview | Core course | Exercises | Beyond the core |
|---|---|---|---|---|
| Français | [Présentation](docs/fr/index.md) | [Cours principal](docs/fr/cours/index.md) | [Exercices](docs/fr/exercices/index.md) | [Aller plus loin](docs/fr/aller-plus-loin/index.md) |
| English | [Overview](docs/en/index.md) | [Core course](docs/en/course/index.md) | [Exercises](docs/en/exercises/index.md) | [Beyond the core](docs/en/beyond-core/index.md) |

The two language trees are independent: French pages link only to French sheets, and English pages link only to English sheets.

## Repository structure

```text
.
├── mkdocs.yml                  # site configuration and navigation
├── README.md
└── docs/
    ├── index.md                # language selector
    ├── fr/
    │   ├── index.md
    │   ├── cours/              # core course and exercise links
    │   ├── exercices/          # 6 Markdown sheets + original PDFs
    │   └── aller-plus-loin/
    └── en/
        ├── index.md
        ├── course/
        ├── exercises/          # 6 Markdown sheets + original PDFs
        └── beyond-core/
```

Each course section has a single `index.md` page used by the navigation. The exercise folders contain one Markdown page and one PDF per sheet; the original PDFs are kept as source references.

## Installation and local development

Python 3 with `pip` is required. Install dependencies from the manifest:

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
```

On Windows, activate the environment with `.venv\Scripts\activate` instead.

Start the development server from the `STUDENT_GUIDE/` directory:

```bash
mkdocs serve
```

Open <http://127.0.0.1:8000> in a browser. The server reloads the site when a Markdown file or `mkdocs.yml` changes.

## Building the documentation

```bash
mkdocs build --strict
```

The static site is written to `site/`, which is ignored by Git. The output directory is cleaned before each build by default.

## Accessing the course and exercises

- After starting the server, use the sidebar to choose **Français** or **English**, then open the core course, exercises, or advanced section.
- The [French exercise index](docs/fr/exercices/index.md) and [English exercise index](docs/en/exercises/index.md) list all six sheets. Each entry links to the Markdown version first, with the original PDF as a secondary link.
- Course chapters include small contextual links to the sheet that matches the topic just covered.

You can also read the Markdown files directly on GitHub without building the site, although the rendered theme and navigation are only available through MkDocs.

## Technologies

- [MkDocs](https://www.mkdocs.org/) — static site generator.
- [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/) — theme and navigation features.
- Markdown extensions including PyMdown highlighting, tabbed blocks, task lists, and emoji, plus admonitions and fenced code blocks.
- Python for the toolchain; Git and GitHub for hosting and collaboration.

The appearance is driven entirely by `mkdocs.yml`; no custom CSS or JavaScript is used, and the only configured plugin is MkDocs' built-in `search`.

## Contributing and feedback

Issues and pull requests are welcome on [GitHub](https://github.com/S-L-A-K-E-R/C_courses/tree/main/STUDENT_GUIDE). When proposing changes:

- Keep the French and English versions aligned.
- Preserve the original exercise PDFs and the source wording of the sheets.
- Run `mkdocs build --strict` before submitting a change to documentation files.

## Credits and sources

The study guide is based on **Tatiana Aubonnet's** original C course (2008), drawing primarily from exercises shared by **[S-L-A-K-E-R](https://github.com/S-L-A-K-E-R)**.

Adaptation, organization, writing, formatting, and documentation: **[1KuMo](https://github.com/1KuMo)**. The original teaching material remains the work of its author; the work listed above concerns its adaptation and presentation in this repository.

Special thanks to **Tatiana Aubonnet** for the original course, which served as the foundation for this work.

### Source and rights note

- Tatiana Aubonnet, *Algorithmes et programmation — Langage C*, 192-slide PDF (`CoursC_2008.pdf`, PDF creation date 1 October 2008). Consulted for topic coverage; no public reuse license or canonical URL verified. The source PDF is not redistributed here. The student describes the guide as independently written, rather than a transcription or translation of the slides.
- Original exercises: [S-L-A-K-E-R/C_courses — EXERCISES/LAB_GENERAL](https://github.com/S-L-A-K-E-R/C_courses/tree/main/EXERCISES/LAB_GENERAL), under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/) to the extent the author holds the rights. Markdown versions adapt exercise statements; the original PDFs are retained unchanged for offline/site access.
- This is a student contribution, not a replacement for official course materials.

## AI transparency

AI tools were used to assist with the technical and presentation-related parts of this project, particularly the documentation structure, MkDocs configuration, YAML setup, and content formatting. Feedback and contributions are always welcome!

```text
 /\_/\\  
( o.o ) 
 > ^ <  
           ____  __     __    ____
          (_  _)/  \\  / _\\ (    \\
            )( (  O )/    \\ ) D (
           (__) \\__/\\_/\\_/(____/
```
