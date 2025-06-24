
# Hướng dẫn sử dụng Git để đẩy file lên GitHub

## ✅ B1: Mở Git Bash và vào thư mục code

```bash
cd /c/C++
```

---

## ✅ B2: Thêm file mới và đẩy lên GitHub

Ví dụ: muốn thêm file `cau4.cpp`

```bash
git add cau4.cpp
git commit -m "Thêm file cau4.cpp"
git push
```

---

## 🔍 Kiểm tra kết nối GitHub (nếu cần)

```bash
git remote -v
```

Kết quả đúng sẽ giống:

```
origin  https://github.com/DSA-DNTU/LTViet.git (fetch)
origin  https://github.com/DSA-DNTU/LTViet.git (push)
```

---

## ⚠️ Ghi nhớ

- **Không cần git init lại**
- **Không cần add remote lại**
- Chỉ cần `add`, `commit`, `push` là đủ

---

## 📌 Mẹo

- Có thể mở thư mục bằng Git Bash bằng cách:
  - Mở thư mục `C:\C++` bằng File Explorer
  - Nhấp chuột phải → Chọn **“Git Bash Here”**
