# 🎮 AP Gaming Shop (OOP Team Rewrite)

یک فروشگاه بازی با رابط کاربری متنی (Console-based) که با زبان ++C پیاده‌سازی شده و حالا به‌صورت تیمی و با رعایت اصول شی‌گرایی (OOP) بازنویسی می‌شود.

---

## ✨ ویژگی‌های پروژه

- مدیریت محصولات (افزودن، حذف، جستجو و مشاهده)
- پنل ادمین با پسورد
- کیف پول فروشگاه و کاربران
- سبد خرید برای کاربران
- دسته‌بندی محصولات
- رنگ‌بندی و رابط کاربری جذاب برای کنسول

---

## 🧠 اهداف بازنویسی پروژه

- پیاده‌سازی اصول **شی‌گرایی** (Object-Oriented Programming)
- تمرین کار تیمی با استفاده از **Git** و **GitHub**
- جداسازی کدها به فایل‌های مستقل
- ساختار ماژولارتر، تمیزتر و قابل نگهداری‌تر

---

## 👥 اعضای تیم

| نام | نقش |
|-----|-----|
| **Mahdi Karzari** | طراحی کلاس `User` + مدیریت کیف پول و سبد خرید + هدایت پروژه |
| **Mahyar Mahmudi** | طراحی کلاس `Product` و `CartItem` + منطق افزودن/حذف محصول |
| **Amirreza Arab Shahrab** | طراحی کلاس `Store` + پنل ادمین و سرمایه‌گذاری + نمایش موجودی و قیمت کلی |

---

## 🧱 ساختار کلاس‌های OOP

- `Product`: مدیریت مشخصات هر محصول
- `CartItem`: آیتم‌های داخل سبد خرید
- `User`: مدیریت کیف پول و سبد خرید کاربر
- `Store`: انبار و موجودی فروشگاه + عملیات ادمین

---

## 🛠 دستورالعمل همکاری تیمی با Git

۱. هر عضو باید ریپازیتوری رو **fork** یا **clone** کنه.  
۲. برای هر فیچر جدید، یه **branch** جداگانه ساخته بشه (مثلاً `feature/add-to-cart`)  
۳. پس از اتمام کار، **pull request** ارسال بشه تا تغییرات بررسی و مرج بشن.  
۴. بعد از هر مرج، همه اعضا با `git pull origin main` پروژه‌شون رو آپدیت کنن.

---

## ⚙️ نحوه بیلد کردن پروژه با CMake

برای اجرای پروژه، فقط کافیه `CMake` و یک کامپایلر C++ مثل `g++` یا Visual Studio داشته باشید.

### ✅ مراحل ساخت (Build) پروژه:

```bash
mkdir build
cd build
cmake ..
cmake --build .
