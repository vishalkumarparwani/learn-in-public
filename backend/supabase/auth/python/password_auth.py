from dotenv import load_dotenv
from supabase import create_client
import os

load_dotenv("backend/supabase/.env")

url = os.getenv("SUPABASE_URL")
key = os.getenv("SUPABASE_KEY")

if not url or not key:
    raise ValueError("Missing supabase URL or KEY in .env")

supabase = create_client(url, key)

def sign_up(email, password):
    return supabase.auth.sign_up({
        "email": email,
        "password": password
    })

def sign_in(email, password):
    return supabase.auth.sign_in_with_password({
        "email": email,
        "password": password
    })

def sign_out():
    supabase.auth.sign_out()

def get_user():
    return supabase.auth.get_user()

def update_password(new_password):
    return supabase.auth.update_user({
        "password": new_password
    })

def reset_password(email):
    return supabase.auth.reset_password_for_email(email)


def main():
    while True:
        print("\n--- Supabase Auth Practice ---")
        print("1. Sign up")
        print("2. Sign in")
        print("3. Get current user")
        print("4. Sign out")
        print("5. Reset password")
        print("6. Update password")
        print("0. Exit")

        choice = input("Chose an option: ").strip()

        try:
            if choice == "1":
                email = input("Email: ").strip()
                password = input("Password: ")
                response = sign_up(email, password)
                if response.user:
                    print("User created:", response.user.email)
                    if not response.session:
                        print("Check your email to confirm your account.")
                else:
                    print("Sign-up completed; check your email if required.")

            elif choice == "2":
                email = input("Email: ").strip()
                password = input("Password: ")
                response = sign_in(email, password)
                print("Signed in:", response.user.email)

            elif choice == "3":
                response = get_user()
                print("Current user:", response.user.email)

            elif choice == "4":
                sign_out()
                print("Signed out.")

            elif choice == "5":
                email = input("Account email: ").strip()
                reset_password(email)
                print("If the account can receive recovery email, check your inbox.")

            elif choice == "6":
                new_password = input("New password: ")
                update_password(new_password)
                print("Password updated.")

            elif choice == "0":
                break

            else:
                print("Invalid option. Try again.")

        except Exception as error:
            print("Authentication error:", error)


if __name__ == "__main__":
    main()