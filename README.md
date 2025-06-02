# QuickNote

> Take notes...quickly. From your terminal. Like a boss.

---

## 🚀 What is QuickNote?

QuickNote is a tiny but mighty command-line tool I built to **quickly capture thoughts**, without having to open editors or create random text files all over the place. It lives in your terminal and was hacked together in *C++*.

Still in development, but here’s what it can do right now:

---

## ✨ Features

- 📌 **Quick Note-Taking**
  Save notes instantly from the terminal:
  ```bash
  qn "Hello World"

- 🏷️ **Tag Your Notes**
  Categorize your notes using --tag or -t:
```bash
qn "Hmm, looks good...I guess." --tag thoughts
qn "Epic!!" -t mood
```

- 📁 **Link Notes to Projects**
  Use --project or -p to tie notes to specific projects:
```bash
qn "You will love it." --project quicknote
qn "Fix parser logic." -t debug -p MyLang
```

- 📄 **List Notes**
  Show today’s notes (default), or list all notes:
```bash
qn -l         # Shows today's notes
qn -l all     # Shows all saved notes
```

---

## 🛠️ Installation

You can either grab a prebuilt binary from [releases](https://github.com/uniStacker/quicknote/releases)  — or build it yourself in just a minute.

### Build it manually (Linux)
```bash
# 0. Install git if you don't have it
sudo apt update && sudo apt install git

# 1. Clone the repo and enter the directory
git clone https://github.com/uniStacker/quicknote.git
cd quicknote

# 2. Build it
make
```

You’ll find the qn binary inside the bin/ directory.

### Add it to your PATH
```bash
sudo mv build/bin/qn /usr/local/bin/
```

Now you can call qn from anywhere. Enjoy the terminal productivity boost. 🚀


---

## 🧠 Coming Soon

- Search notes

- Delete/edit notes

- Date filtering

- Config file support

---

## 🤘 Final Note

Still a work-in-progress, but usable. Feel free to fork it, improve it, or shout at me with ideas.
Check it out on GitHub: [QuickNote](https://github.com/uniStacker/quicknote)
